
 # getopt概要

 # データ構造

```c
typedef struct s_private_opting {
	bool	is_parsed; // パースし終わったかどうか。 初期化時 false
	int		optpos; // 現在のオプションの場所 初期化時 1
}	t_private_opting;

typedef struct s_opting {
	int					argc; // argc 初期化時 ms_init_optingの引数
	char				*argv; // argv 初期化時 ms_init_optingの引数
	char				*optstring; // オプションとして解析可能な文字の集合 ms_init_optingの引数
	bool				is_skip_double_hyphen; // `--`をスキップするかどうか。 初期化時 true
	bool				is_valid; // 有効なオプションの時 true 初期化時 false
	int					optind; // 次にチェックするargvのインデックス。初期化時１
	int 				optopt; // オプション文字 初期化時 -1
	t_private_opting	private; // 内部変数
}	t_opting;
```

 # 使い方
 1. ms_init_optingでt_opting型の変数を初期化する。
 2. ms_getoptでオプションを取得する。
 3. trueを返したらoptoptを参照してopt文字を取得する
 3. optindの値を使って残りの引数を参照する。

 # 変数
 * is_skip_double_hyphenをfalseに設定することで、ms_getoptが`--`でfalseを返すようになる。
