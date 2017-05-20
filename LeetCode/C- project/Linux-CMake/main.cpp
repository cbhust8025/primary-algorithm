#include "head.h"
#include "BackTrackingHelper.h"
#include<queue>
#include "ListHelper.h"
#include "VectorHelper.h"
#include "StringHelper.h"
#include "DynamicProgrammingHelper.h"
#include "designHelper.h"
int main() {
    string s1 = "1";
    string s2 = "1.0";
    cout << StringHelper::compareVersion(s1, s2) << endl;
    return 0;
}