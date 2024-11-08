

typedef struct variable	*sh_var_value_func_t(struct variable *);
typedef struct variable	*sh_var_assign_func_t(struct variable *, char *,
							arrayind_t, char *);

#ifndef PTR_T
# define PTR_T void *
#endif

typedef struct bucket_contents
{
	struct bucket_contents *next; /* Link to next hashed key in this bucket. */
	char *key;                    /* What we look up. */
	PTR_T data;                   /* What we really want. */
	unsigned int khash;           /* What key hashes to */
	int					times_found;
	/* Number of times this item has been found. */
}						BUCKET_CONTENTS;
typedef struct hash_table
{
	BUCKET_CONTENTS **bucket_array; /* Where the data is kept. */
	int nbuckets;                   /* How many buckets does this table have. */
	int nentries;                   /* How many entries does this table have. */
}						HASH_TABLE;
/* A variable context. */
typedef struct var_context
{
	char *name; /* empty or NULL means global context */
	int scope;  /* 0 means global context */
	int					flags;
	struct var_context *up;   /* previous function calls */
	struct var_context *down; /* down towards global context */
	HASH_TABLE *table;        /* variables at this scope */
}						VAR_CONTEXT;

/* The current list of shell variables, including function scopes */
VAR_CONTEXT				*shell_variables = (VAR_CONTEXT *)NULL;

typedef struct variable
{
	char *name;                         /* Symbol that the user types. */
	char *value;                        /* Value that is returned. */
	char *exportstr;                    /* String for the environment. */
	sh_var_value_func_t *dynamic_value; /* Function called to return a `dynamic'
					value for a variable, like $SECONDS
					or $RANDOM. */
	sh_var_assign_func_t *assign_func;  /* Function called when this `special
						variable' is assigned a value in
						bind_variable. */
	int attributes;                     /* export, readonly, array,
        invisible... */
	int					context;
	/* Which context this variable belongs to. */
}						SHELL_VAR;

static void	create_variable_tables(void)
{
	if (shell_variables == 0)
	{
		shell_variables = global_variables = new_var_context((char *)NULL, 0);
		shell_variables->scope = 0;
		shell_variables->table = hash_create(VARIABLES_HASH_BUCKETS);
	}
	if (shell_functions == 0)
		shell_functions = hash_create(FUNCTIONS_HASH_BUCKETS);
}

SHELL_VAR	*find_variable(const char *name)
{
	SHELL_VAR	*v;
	int			flags;

	last_table_searched = 0;
	flags = 0;
	if (expanding_redir == 0 && (assigning_in_environment || executing_builtin))
		flags |= FV_FORCETEMPENV;
	v = find_variable_internal(name, flags);
	if (v && nameref_p(v))
		v = find_variable_nameref(v);
	return (v);
}

void					set_pwd(void);

void	initialize_shell_variables(char **env, int privmode)
{
	SHELL_VAR	*temp_var;
	int			privmode;
	SHELL_VAR	*temp_var;
	size_t		namelen;
	size_t		namelen;
	size_t		namelen;
	char		node_name[22];

	char *name, *string, *temp_string;
	int c, char_index, string_index, string_length, ro;
	create_variable_tables();
	for (string_index = 0; env && (string = env[string_index++]);)
	{
		char_index = 0;
		name = string;
		while ((c = *string++) && c != '=')
			;
		if (string[-1] == '=')
			char_index = string - name - 1;
		/* If there are weird things in the environment, like `=xxx' or a
		string without an `=', just skip them. */
		if (char_index == 0)
			continue ;
		/* ASSERT(name[char_index] == '=') */
		name[char_index] = '\0';
		/* Now, name = env variable name, string = env variable value, and
		char_index == strlen (name) */
		temp_var = (SHELL_VAR *)NULL;
		{
			ro = 0;
			/* If we processed a command-line option that caused SHELLOPTS to be
				set,
					it may already be set (and read-only) by the time we process
				the shell's environment. */
			if (legal_identifier(name))
			{
				temp_var = bind_variable(name, string, 0);
				if (temp_var)
				{
					VSETATTR(temp_var, (att_exported | att_imported));
					if (ro)
						VSETATTR(temp_var, att_readonly);
				}
			}
			else
			{
				temp_var = bind_invalid_envvar(name, string, 0);
				if (temp_var)
					VSETATTR(temp_var,
						(att_exported | att_imported | att_invisible));
			}
			if (temp_var)
				array_needs_making = 1;
		}
		name[char_index] = '=';
		/* temp_var can be NULL if it was an exported function with a syntax
		error (a different bug, but it still shouldn't dump core). */
		if (temp_var && function_p(temp_var) == 0) /* XXX not yet */
		{
			CACHE_IMPORTSTR(temp_var, name);
		}
	}
	set_pwd();
	/* Set up initial value of $_ */
	temp_var = set_if_not("_", dollar_vars[0]);
	/* Remember this pid. */
	dollar_dollar_pid = getpid();
	/* Now make our own defaults in case the vars that we think are
		important are missing. */
	temp_var = set_if_not("PATH", DEFAULT_PATH_VALUE);
	temp_var = set_if_not("TERM", "dumb");
	/* set up the prompts. */
#if defined(PROMPT_STRING_DECODE)
	set_if_not("PS1", primary_prompt);
#else
	if (current_user.uid == -1)
		get_current_user_info();
	set_if_not("PS1", current_user.euid == 0 ? "# " : primary_prompt);
#endif
	set_if_not("PS2", secondary_prompt);
	/* Don't allow IFS to be imported from the environment. */
	temp_var = bind_variable("IFS", " \t\n", 0);
	setifs(temp_var);
	/* Magic machine types.  Pretty convenient. */
	set_machine_vars();
	/* Default MAILCHECK for interactive shells.  Defer the creation of a
		default MAILPATH until the startup files are read, because MAIL
		names a mail file if MAILPATH is not set, and we should provide a
		default only if neither is set. */
	VSETATTR(temp_var, att_integer);
	/* Do some things with shell level. */
	initialize_shell_level();
	set_ppid();
	set_argv0();
	/* Initialize the `getopts' stuff. */
	temp_var = bind_variable("OPTIND", "1", 0);
	VSETATTR(temp_var, att_integer);
	getopts_reset(0);
	bind_variable("OPTERR", "1", 0);
	sh_opterr = 1;
	if (login_shell == 1 && posixly_correct == 0)
		set_home_var();
	/* Get the full pathname to THIS shell, and set the BASH variable
		to it. */
	name = get_bash_name();
	temp_var = bind_variable("BASH", name, 0);
	free(name);
	/* Make the exported environment variable SHELL be the user's login
		shell.  Note that the `tset' command looks at this variable
		to determine what style of commands to output; if it ends in "csh",
		then C-shell commands are output, else Bourne shell commands. */
	set_shell_var();
	/* Make a variable called BASH_VERSION which contains the version info. */
	bind_variable("BASH_VERSION", shell_version_string(), 0);
	if (command_execution_string)
		bind_variable("BASH_EXECUTION_STRING", command_execution_string, 0);
	/* Find out if we're supposed to be in Posix.2 mode via an
		environment variable. */
	temp_var = find_variable("POSIXLY_CORRECT");
	if (!temp_var)
		temp_var = find_variable("POSIX_PEDANTIC");
	if (temp_var && imported_p(temp_var))
		sv_strict_posix(temp_var->name);
	/* Set history variables to defaults, and then do whatever we would
		do if the variable had just been set.  Do this only in the case
		that we are remembering commands on the history list. */
	if (remember_on_history)
	{
		name = bash_tilde_expand(posixly_correct ? "~/.sh_history" : "~/.bash_history",
				0);
		set_if_not("HISTFILE", name);
		free(name);
	}
	/* Seed the random number generators. */
	seedrand();
	seedrand32();
	/* Handle some "special" variables that we may have inherited from a
		parent shell. */
	temp_var = find_variable("IGNOREEOF");
	if (!temp_var)
		temp_var = find_variable("ignoreeof");
	if (temp_var && imported_p(temp_var))
		sv_ignoreeof(temp_var->name);
	sv_history_control("HISTCONTROL");
	sv_histignore("HISTIGNORE");
	sv_histtimefmt("HISTTIMEFORMAT");
	/* Get the user's real and effective user ids. */
	uidset();
	temp_var = set_if_not("BASH_LOADABLES_PATH",
			DEFAULT_LOADABLE_BUILTINS_PATH);
	temp_var = find_variable("BASH_XTRACEFD");
	if (temp_var && imported_p(temp_var))
		sv_xtracefd(temp_var->name);
	/* Initialize the dynamic variables, and seed their values. */
	initialize_dynamic_variables();
}

void	set_pwd(void)
{
	SHELL_VAR *temp_var, *home_var;
	char *temp_string, *home_string, *current_dir;

	home_var = find_variable("HOME");
	home_string = home_var ? value_cell(home_var) : (char *)NULL;

	temp_var = find_variable("PWD");
	/* Follow posix rules for importing PWD */
	if (temp_var && imported_p(temp_var) && (temp_string = value_cell(temp_var))
		&& temp_string[0] == '/' && same_file(temp_string, ".",
			(struct stat *)NULL, (struct stat *)NULL))
	{
		current_dir = sh_canonpath(temp_string,
				PATH_CHECKDOTDOT | PATH_CHECKEXISTS);
		if (current_dir == 0)
			current_dir = get_working_directory("shell_init");
		else
			set_working_directory(current_dir);
		if (posixly_correct && current_dir)
		{
			temp_var = bind_variable("PWD", current_dir, 0);
			set_auto_export(temp_var);
		}
		free(current_dir);
	}
	else if (home_string && interactive_shell && login_shell
		&& same_file(home_string, ".", (struct stat *)NULL,
			(struct stat *)NULL))
	{
		set_working_directory(home_string);
		temp_var = bind_variable("PWD", home_string, 0);
		set_auto_export(temp_var);
	}
	else
	{
		temp_string = get_working_directory("shell-init");
		if (temp_string)
		{
			temp_var = bind_variable("PWD", temp_string, 0);
			set_auto_export(temp_var);
			free(temp_string);
		}
	}

	/* According to the Single Unix Specification, v2, $OLDPWD is an
		`environment variable' and therefore should be auto-exported.  If we
		don't find OLDPWD in the environment,
			or it doesn't name a directory,
		make a dummy invisible variable for OLDPWD,
			and mark it as exported. */
	temp_var = find_variable("OLDPWD");
#if defined(OLDPWD_CHECK_DIRECTORY)
	if (temp_var == 0 || value_cell(temp_var) == 0
		|| file_isdir(value_cell(temp_var)) == 0)
#else
	if (temp_var == 0 || value_cell(temp_var) == 0)
#endif

	{
		temp_var = bind_variable("OLDPWD", (char *)NULL, 0);
		VSETATTR(temp_var, (att_exported | att_invisible));
	}
}