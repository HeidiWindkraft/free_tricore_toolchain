
%%

/* CALLOUT ftct_intarith_primary_leaf_expression: INTEGER_LITERAL | IDENTIFIER; */

ftct_intarith_primary_expression
	: ftct_intarith_primary_leaf_expression { $$ = $1; }
	| '(' ftct_intarith_expression ')' { $$ = $2; }
	;

ftct_intarith_postfix_expression
	: ftct_intarith_primary_expression { $$ = $1; }
	| ftct_intarith_postfix_expression '[' ftct_intarith_expression ']' { $$ = ftct_intarith_subscript($1,$3); }
	| ftct_intarith_postfix_expression '(' ftct_intarith_argument_expression_list ')' {
		$$ = ftct_intarith_call($1,$3);
	}
	/* | ftct_intarith_postfix_expression '.' IDENTIFIER
	| ftct_intarith_postfix_expression PTR_OP IDENTIFIER
	| ftct_intarith_postfix_expression INC_OP
	| ftct_intarith_postfix_expression DEC_OP */
	;

ftct_intarith_unary_expression
	: ftct_intarith_postfix_expression { $$ = $1; }
	| '+' ftct_intarith_unary_expression { $$ = ftct_intarith_unary_plus($2); }
	| '-' ftct_intarith_unary_expression { $$ = ftct_intarith_neg($2); }
	| '~' ftct_intarith_unary_expression { $$ = ftct_intarith_bitnot($2); }
	| '!' ftct_intarith_unary_expression { $$ = ftct_intarith_lognot($2); }
	;


ftct_intarith_multiplicative_expression
	: ftct_intarith_unary_expression { $$ = $1; }
	| ftct_intarith_multiplicative_expression '*' ftct_intarith_unary_expression { $$ = ftct_intarith_mul($1,$3); }
	| ftct_intarith_multiplicative_expression '/' ftct_intarith_unary_expression { $$ = ftct_intarith_div($1,$3); }
	| ftct_intarith_multiplicative_expression '%' ftct_intarith_unary_expression { $$ = ftct_intarith_mod($1,$3); }
	;

ftct_intarith_additive_expression
	: ftct_intarith_multiplicative_expression { $$ = $1; }
	| ftct_intarith_additive_expression '+' ftct_intarith_multiplicative_expression { $$ = ftct_intarith_add($1,$3); }
	| ftct_intarith_additive_expression '-' ftct_intarith_multiplicative_expression { $$ = ftct_intarith_sub($1,$3); }
	;

ftct_intarith_shift_expression
	: ftct_intarith_additive_expression { $$ = $1; }
	| ftct_intarith_shift_expression LEFT_OP ftct_intarith_additive_expression { $$ = ftct_intarith_shl($1,$3); }
	| ftct_intarith_shift_expression RIGHT_OP ftct_intarith_additive_expression { $$ = ftct_intarith_shr($1,$3); }
	;

ftct_intarith_relational_expression
	: ftct_intarith_shift_expression { $$ = $1; }
	| ftct_intarith_relational_expression '<' ftct_intarith_shift_expression { $$ = ftct_intarith_less($1,$3); }
	| ftct_intarith_relational_expression '>' ftct_intarith_shift_expression { $$ = ftct_intarith_greater($1,$3); }
	| ftct_intarith_relational_expression LE_OP ftct_intarith_shift_expression { $$ = ftct_intarith_less_eq($1,$3); }
	| ftct_intarith_relational_expression GE_OP ftct_intarith_shift_expression { $$ = ftct_intarith_greater_eq($1,$3); }
	;

ftct_intarith_equality_expression
	: ftct_intarith_relational_expression { $$ = $1; }
	| ftct_intarith_equality_expression EQ_OP ftct_intarith_relational_expression { $$ = ftct_intarith_eq($1,$3); }
	| ftct_intarith_equality_expression NE_OP ftct_intarith_relational_expression { $$ = ftct_intarith_neq($1,$3); }
	;

ftct_intarith_and_expression
	: ftct_intarith_equality_expression { $$ = $1; }
	| ftct_intarith_and_expression '&' ftct_intarith_equality_expression { $$ = ftct_intarith_bitand($1,$3); }
	;

ftct_intarith_exclusive_or_expression
	: ftct_intarith_and_expression { $$ = $1; }
	| ftct_intarith_exclusive_or_expression '^' ftct_intarith_and_expression { $$ = ftct_intarith_xor($1,$3); }
	;

ftct_intarith_inclusive_or_expression
	: ftct_intarith_exclusive_or_expression { $$ = $1; }
	| ftct_intarith_inclusive_or_expression '|' ftct_intarith_exclusive_or_expression {
		$$ = ftct_intarith_bitor($1,$3);
	};

ftct_intarith_logical_and_expression
	: ftct_intarith_inclusive_or_expression { $$ = $1; }
	| ftct_intarith_logical_and_expression AND_OP ftct_intarith_inclusive_or_expression {
		$$ = ftct_intarith_logand($1,$3);
	};

ftct_intarith_logical_or_expression
	: ftct_intarith_logical_and_expression { $$ = $1; }
	| ftct_intarith_logical_or_expression OR_OP ftct_intarith_logical_and_expression {
		$$ = ftct_intarith_logor($1,$3);
	};

ftct_intarith_conditional_expression
	: ftct_intarith_logical_or_expression { $$ = $1; }
	| ftct_intarith_logical_or_expression '?' ftct_intarith_expression ':' ftct_intarith_conditional_expression {
		$$ = ftct_intarith_if_then_else($1,$3,$5);
	};

ftct_intarith_expression: ftct_intarith_conditional_expression { $$ = $1; }

