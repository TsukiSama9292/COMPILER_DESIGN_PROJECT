# 編譯器設計 作業1
```bash
docker-compose down
docker-compose up -d
```

void yyerror(const char *s) {
    int report_line = yylineno > 0 ? yylineno - 1 : 0;
    fprintf(stderr, "❌ 語法錯誤：%s 在第 %d 行\n", s, report_line);
}

int main() {
    yyparse();
    return 0;
}