# そのほかの関数

## シェル変数系
### ms_getshenv
```c
char	*ms_getshenv(const char *name)
```
- **説明**: getenvのシェル変数版 see getenv(3)
- **戻り値**:
  - 成功: nameに対応した変数名
  - 失敗: NULL

### ms_setshenv
```c
int	ms_setshenv(const char *name, const char *value, int overwrite)
```
- **説明**: setenvのシェル変数版 see setenv(3)
- **戻り値**:
  - 成功: 0
  - 失敗: -1 errnoが設定される。
- **エラー**:
  - EINVAL: nameが、NULLか長さが0か、'='が含まれている場合
  - ENOMEM: 新しい変数を足すためのメモリが不足しているとき

### ms_unsetshenv
```c
int ms_unsetenv(const char *name)
```
- **説明**: unsetenvのシェル変数版 see unsetenv(3)
- **戻り値**:
  - 成功: 0
  - 失敗: -1 errnoが設定される。
- **エラー**:
  - EINVAL: nameが、NULLか長さが0か、'='が含まれている場合

## 環境変数系

### ms_setshenv
```c
int	ms_setenv(const char *name, const char *value, int overwrite)
```
- **説明**: see setenv(3)

### ms_unsetenv
```c
int ms_unsetenv(const char *name)
```
- **説明**: see unsetenv(3)
