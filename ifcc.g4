grammar ifcc;

prog: function*;

function: ( TYPE | 'void') IDENTIFIER funcParams block;

funcParams: '(' paramList? ')';

paramList: declaration | paramList ',' declaration;

declaration: TYPE IDENTIFIER;

block: '{' statement* '}';

statement:
	RETURN expression? ';'	# returnStatement
	| expression ';'		# exprStatement;

expression:
	CONST										# constExpr
	| expression ADD_SUB_OPERATOR expression	# addSubExpr
	| '(' expression ')'						# parExpr
	| IDENTIFIER '=' expression					# assignExpr;

TYPE: 'int' | 'char';
RETURN: 'return';

CONST: DIGIT+;
IDENTIFIER: NONDIGIT (NONDIGIT | DIGIT)*;

fragment NONDIGIT: [a-zA-Z_];
fragment DIGIT: [0-9];

ADD_SUB_OPERATOR: '+' | '-';

COMMENT: ('/*' .*? '*/' | '//' .*? '\n') -> skip;
DIRECTIVE: '#' .*? '\n' -> skip;
WS: [ \t\r\n]+ -> channel(HIDDEN);