grammar ifcc;

prog: function*;

function: ( TYPE | 'void') IDENTIFIER funcParams block;

funcParams: '(' paramList? ')';

paramList: declaration | paramList ',' declaration;

declaration: TYPE IDENTIFIER;

block: '{' statement* '}';

statement: returnStatement;

returnStatement: RETURN expression? ';';

expression: CONST;

TYPE: 'int' | 'char';
RETURN: 'return';

CONST: DIGIT+;
IDENTIFIER: NONDIGIT (NONDIGIT | DIGIT)*;

fragment NONDIGIT: [a-zA-Z_];
fragment DIGIT: [0-9];

COMMENT: ('/*' .*? '*/' | '//' .*? '\n') -> skip;
DIRECTIVE: '#' .*? '\n' -> skip;
WS: [ \t\r\n]+ -> channel(HIDDEN);