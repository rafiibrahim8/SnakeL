#include<conio.h>
void typEff(char str[],unsigned long sleepTime);

void about(void)
{
    typEff("Author: Ibrahim Rafi\nWeb: http://ibrahimts.cf\nGitHub: https://github.com/rafiibrahim8\n\nThis program/game/software uses a function gotoxy() from stackoverflow.com\nURL: https://stackoverflow.com/posts/20727827/revisions\nat\nhttps://stackoverflow.com/questions/9782287/undefined-reference-to-gotoxy-in-c \n\n\n",10);
    typEff("--------------------------------------------------------------------------------",5);
    typEff("This software is provided with MIT License.\n\n\nCopyright (c) 2017 Ibrahim Rafi\n\nPermission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the \"Software\"), to deal in \nthe Software without restriction, including without limitation the rights to \nuse, copy, modify, merge, publish, distribute, sublicense, and/or sell copies \nof the Software, and to permit persons to whom the Software is furnished to do \nso, subject to the following conditions:\n\nThe above copyright notice and this permission notice shall be included in all \ncopies or substantial portions of the Software.\n\nTHE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR \nIMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, \nFITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE \nAUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER \nLIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, \nOUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE \nSOFTWARE.\n",15);
    typEff("--------------------------------------------------------------------------------",5);
    typEff("\n\n\n\t\tPress a key to continue to game.",5);
    getch();
}
