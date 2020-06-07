// Solution to pointer lab5

int main() {
    
    char *s ;
    char foo[] = "Hello World";

    s = foo;
    printf("s is %s\n",s);
    
//    s[0] = foo;
    printf("s[0] is %c\n",*s);
    return(0);
}

