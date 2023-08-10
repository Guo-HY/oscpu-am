#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
    if (argc != 3) {
        printf("usage : ./std_convert <input bin> <output vlog>\n");
        exit(1);
    }

	FILE *in;
	FILE *out;

	unsigned char mem[32];

    out = fopen(argv[2],"w");

    in  = fopen(argv[1],"rb");
    fprintf(out,"@1c000000\n");
    while(!feof(in)) {
        if (fread(mem,1,1,in) != 1) {
            fprintf(out,"%02x\n", mem[0]);
            break;
        }
        fprintf(out,"%02x\n", mem[0]);
    }

    fclose(in);
    fclose(out);
    return 0;
}
