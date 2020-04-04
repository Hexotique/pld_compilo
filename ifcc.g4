grammar ifcc;

prog: function+;

function: ( TYPE | 'void') IDENTIFIER funcParams block;

funcParams: '(' paramList? ')';

paramList: declaration | paramList ',' declaration;

declaration: TYPE IDENTIFIER;

block: '{' statement* '}';

statement:
	RETURN expression? ';'				# returnStatement
	| declaration (',' IDENTIFIER)* ';'	# declarationStatement
	| declaration '=' expression ';'	# definitionStatement
	| expression ';'					# exprStatement;

expression:
	CONST										# constExpr
	| IDENTIFIER								# varExpr
	| expression MULT_DIV_OPERATOR expression	# multDivExpr
	| expression ADD_SUB_OPERATOR expression	# addSubExpr
	| expression BIT_OPERATOR expression		# bitExpr
	| '(' expression ')'						# parExpr
	| CHAR						                # charExpr
	| IDENTIFIER '=' expression					# assignExpr;


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

COMMENT: ('/*' .*? '*/' | '//' .*? '\n') -> skip;
DIRECTIVE: '#' .*? '\n' -> skip;
WS: [ \t\r\n]+ -> channel(HIDDEN);
