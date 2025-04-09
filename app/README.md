# 1.產生掃描器
```bash
flex lex.l
```
# 2.編譯
```bash
gcc -o lexer lex.yy.c -lfl
```
# 3.執行
```bash
./lexer < test.py
```