/*
~ Author    : @tridib_2003
~ Title     : TEST - Life, the Universe, and Everything
~ Link      : https://www.spoj.com/problems/TEST/
*/

#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    int n;
    while(1) {
        scanf("%d",&n);
        if(n==42)
            break;
        printf("%d\n",n);
    }
    return 0;
}
