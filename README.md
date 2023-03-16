# bnf

Backus–Naur form interpreter written in C++

## Usage example

```
// filename: example.bnf

 <expr> ::= <term> "+" <expr>
         |  <term>

 <term> ::= <factor> "*" <term>
         |  <factor>

 <factor> ::= "(" <expr> ")"
           |  <const>

 <const> ::= integer
```

```shell
bnf -c example.bnf -o example.o
```

```shell
bnf -i example.o

> expr ? 1 + 1
true

> expr ? input
false

<Ctrl+D>
```
