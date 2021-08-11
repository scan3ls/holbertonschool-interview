#ifndef REGEX_H
#define REGEX_H

#define AT_END(X) (X[0] == '\0')
#define STAR_RULE(X) (X[1] == '*')
#define DOT_RULE(X) (X[0] == '.')
#define NOT_DOT_RULE(X) (X[0] != '.')
#define SAME_CHAR(X, Y) (X[0] == Y[0])
#define NOT_SAME_CHAR(X, Y) (X[0] != Y[0])
#define TRUE 1
#define FALSE 0

int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */
