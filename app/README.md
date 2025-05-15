# 小專題報告1
```
A. 請自選一段至少10行以上的任何語言程式碼作為詞彙分析器之輸入(source program)。
B. 以程式碼語言的特性撰寫FLEX程式以定義詞彙單位(lex.l)。
C. 試用FLEX編譯器產生lex.yy.c程式原始碼，並以你的理解來分析說明。
D. 試以lex.yy.cc編譯而成的程式作為詞彙分析器，並以自選程式碼片段作為輸入，產出詞彙單位序列與詞彙統計。
```
## 1. 產生掃描器
```bash
flex lex.l
```
## 2. 編譯
```bash
gcc -o lexer lex.yy.c -lfl
```
## 3. 執行
```bash
./lexer < test.c
```

# 小專題報告2
## 題目
```
A. 請以小專題報告1為例(可視狀況調整輸入原始程式碼)，編寫一個YaCC/bison Specification，並以Flex建立YaCC/bison的詞彙分析器，以建立語法分析器(Parser)，語法分析器需能在分析語法後於螢幕上列印出分析的原始程式碼行數。
B. 改寫A小題的語法分析器，使其能在螢幕上列印語法分析錯誤，並修改輸入原始程式碼至少產生兩處錯誤。
```
## 1. 建立 translate.tab.c 和 translate.tab.h
```bash
bison -d translate.y # 產出 translate.tab.c 和 translate.tab.h
```
## 2. 產生掃描器
```bash
flex lex.l
```
## 3. 編譯
```bash
gcc translate.tab.c lex.yy.c -lfl
```
## 4. 執行
```bash
./a.out < test.py
```
```bash
bison -d translate.y
flex lex.l
gcc translate.tab.c lex.yy.c -lfl -o parser
./parser < test.c
./parser < test_error.c
```