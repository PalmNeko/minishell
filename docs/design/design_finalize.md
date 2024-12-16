# minishellの終了処理
## 終了条件
1. exitコマンドの実行
2. EOFの受信

## void ms_cleanup_and_exit(int status)
- **説明**
	- 終了時に各種メモリの解放を行ったのち引数に指定されたステータスで終了を行う。
	- 解放するメモリは初期化パートで動的に確保したメモリを対象とする。
	- この処理に入った場合必ず強制終了を行う。