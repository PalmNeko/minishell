```mermaid
flowchart
A(wait_input)
B("cmd =
parse_command_linebuf(buf)")
C{cmd == NULL}
D{cmd->argc > 0}
E("origin_stdin = dup(0)
origin_stdout = dup(1)")
F("exec_pipline(cmd)")
G("st = wait_pipline(cmd)")
H("close(0); dup2(origin_stdin,0); close(origin_stdin);
close(1); dup2(origin_stdout,0); close(origin_stdout);"
F("free_cmd(cmd)")

A --> B --> C -->|NO| D -->|NO| F --> A
D -->|YES| E --> F
C -->|YES| print_Syntaxerror
```