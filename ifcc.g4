grammar ifcc;

prog: function+;

function: ( TYPE | 'void') IDENTIFIER funcParams block;

funcParams: '(' (declaration (',' declaration)*)? ')';

declaration: TYPE IDENTIFIER;

define: declaration '=' expression;

block: '{' statement* '}';

elif: 'else if' '(' expression ')' statement;

el: 'else' statement;

statement:
	RETURN expression? ';'																# returnStatement
	| declaration (',' IDENTIFIER)* ';'													# declarationStatement
	| define ';'																		# definitionStatement
	| block																				# blockStatement
	| 'if' '(' expression ')' statement elif* el?										# ifStatement
	| 'for' '(' (define | expression)? ';' expression? ';' expression? ')' statement	# forStatement
	| 'while' '(' expression? ')' statement												# whileStatement
	| expression ';'																	# exprStatement;

expression:
	CONST													# constExpr
	| IDENTIFIER											# varExpr
	| CHAR													# charExpr
	| '!' expression										# notExpr
	| expression MULT_DIV_OPERATOR expression				# multDivExpr
	| expression ADD_SUB_OPERATOR expression				# addSubExpr
	| expression BIT_OPERATOR expression					# bitExpr
	| expression COMP_OPERATOR expression					# compExpr
	| '(' expression ')'									# parExpr
	| IDENTIFIER '=' expression								# assignExpr
	| IDENTIFIER '(' (expression (',' expression)*)? ')'	# funcExpr;

TYPE: 'int' | 'char' | 'int64_t';
RETURN: 'return';

CONST: DIGIT+;
IDENTIFIER: NONDIGIT (NONDIGIT | DIGIT)*;
CHAR: '\'' (~['\\\r\n] | '\\' ESCCHAR) '\'';

fragment NONDIGIT: [a-zA-Z_];
fragment DIGIT: [0-9];
fragment ESCCHAR: ['"?abefnrtv\\];

ADD_SUB_OPERATOR: '+' | '-';
MULT_DIV_OPERATOR: '*' | '/';
BIT_OPERATOR: '^' | '&' | '|';
COMP_OPERATOR: '==' | '!=' | '>' | '<' | '<=' | '>=';

COMMENT: ('/*' .*? '*/' | '//' .*? '\n') -> skip;
DIRECTIVE: '#' .*? '\n' -> skip;
WS: [ \t\r\n]+ -> channel(HIDDEN);
