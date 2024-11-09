# minishell フロー 概要
```mermaid

flowchart TD

	A((開始))
		--> B[[初期化]]
		--> C[[コマンドループ]]
		--> D[[終了]]
		--> Z((終了))
```

初期化
```mermaid
flowchart TD
	A[[初期化]]
```

コマンドループ
```mermaid
flowchart TD

	A[[コマンドループ]]
		--> B[/ループ\]
		--> B[[入力受け取り]]
		--> C[[パース]]
		--> H[[コマンドの実行]]
		--> Z[\ループ/]
```

終了
```mermaid
flowchart TD
	A[[終了]]
```
