# 制御工学実験 TeX テンプレート 

- エクスプローラーでファイルの展開した場所に移動します(ここでは,`C:\Users\ユーザー名\Documents>report5s_uplatex_2024>` としています)． 
- アドレスバーに `powershell.exe` もしくは `pwsh` と入力して `PowerShell` を立ち上げます．
- プロンプトが `PS C:\Users\ユーザー名\Documents>report5s_uplatex_2024>` になります． 
- 下記のコマンドを入力することで,エラーがなければ,`PDF` ファイルが作成されます．

## タイプセットの方法 1

下記のコマンドを `PowerShell` に入力します．

```
uplatex main.tex
uplatex main.tex
dvipdfmx main.dvi
```

## タイプセットの方法 2

下記のコマンドを `PowerShell` に入力します．タイプセット方法 1 のコマンドをまとめて実行します（ちょっと違いますが…）．

```
cluttex -e uplatex main.tex
```


