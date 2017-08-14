#ifndef __GOD_H_
#define __GOD_H_

typedef struct expression Expression, *PExpression;

typedef enum {
    INT_EXPRESSION,
    ADD_EXPRESSION,
    SUB_EXPRESSION,
    MUL_EXPRESSION,
    DIV_EXPRESSION,
    MOD_EXPRESSION,
} ExpressionType;

typedef struct {
    Expression  *left;
    Expression  *right;
} OperatorExpression;

struct expression {
	ExpressionType 	type;
	union {
		int 			int_val;
        	OperatorExpression 	binary_expression;
	}u;
};

/*
	创建运算表达式（加、减、乘、除、求余）

	参数一：表达式类型
	参数二：左操作数
	参数三：右操作数
*/
PExpression create_operation_expression(int, PExpression, PExpression);
PExpression create_add_expression(PExpression, PExpression);

/*
	创建表达式
*/
PExpression create_int_expr(int);

/*
	中序遍历抽象语法树
*/
void print_expr_tree(PExpression);

/*
	执行抽象语法树中的表达式（后序遍历）
*/
void run_expr_tree(PExpression, int *);

#endif
