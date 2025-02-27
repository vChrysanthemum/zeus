#include <string.h>

#include "core/zmalloc.h"
#include "core/sds.h"
#include "core/adlist.h"
#include "core/dict.h"

#include "case.h"
#include "core/stack.h"
#include "event/event.h"
#include "ui/ui.h"

typedef struct testS {} testS;

TEST_CASE("fail stack test")
{
    stack* stack = stackCreate(4);

    testS *a = (testS*)zmalloc(sizeof(testS));
    testS *b = (testS*)zmalloc(sizeof(testS));
    testS *ret;

    stackPush(stack, (void*)a);
    stackPush(stack, (void*)b);

    ret = (testS*)stackPop(stack);
    REQUIRE(b == ret, "err");

    ret = (testS*)stackPop(stack);
    REQUIRE(a == ret, "err");

    stackPush(stack, (void*)a);
    stackPush(stack, (void*)b);
    stackRelease(stack);
}
