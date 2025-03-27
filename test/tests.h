#define assert(condition) \
do { \
    if (!(condition)) { \
	fprintf(stderr, "Assertion failed, file %s, line %d\n", \
		 __FILE__, __LINE__); \
    } \
} while (0)


void runDynamicArrayTests();
void runLinkedListTests();
void runStackTests();
