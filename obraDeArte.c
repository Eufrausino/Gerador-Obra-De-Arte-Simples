#include "obraDeArte.h"

//Exibe a obra de arte
void imprimeQuadro(char quadro[][COLUNAS])
{
	for(int i = 0; i < LINHAS; i++)
	{
		for(int j = 0; j < COLUNAS; j++)printf("%c", quadro[i][j]);
		printf("\n");
	}
}

//Gera valor aleatório para a coordena X do elemento central das obras 1,2 e 3
int geraNumeroAleatorioX()
{
	return (rand()%LINHAS)+1; 
}

//Gera valor aleatório para a coordena Y do elemento central das obras 1,2 e 3
int geraNumeroAleatorioY()
{
	return (rand()%COLUNAS)+1;
}

void geraObra1(char quadro[][COLUNAS], int qtdFiguras)
{
	int colisao[LINHAS][COLUNAS];
	int determinaPosicaoX;
	int determinaPosicaoY;
	
	//Garante que nada será gerado sobre a moldura
	for(int i = 0; i < LINHAS; i++)
	{
		for(int j = 0; j < COLUNAS; j++)
		{
			if(i == 0 || i == LINHAS-1) colisao[i][j] = 1;
			else if(j == 0 || j == COLUNAS-1) colisao[i][j] = 1;
			else colisao[i][j] = 0;
		}
	}
	
	//Gera figura de forma aleatória e garante que figuras não irão se sobrepor
	for(int i = 0; i < qtdFiguras; i++)
	{
		determinaPosicaoX = geraNumeroAleatorioX();
		determinaPosicaoY = geraNumeroAleatorioY();
		if(determinaPosicaoX == 0 || determinaPosicaoX == LINHAS - 1 || determinaPosicaoY == 0 || determinaPosicaoY == COLUNAS -1
		|| colisao[determinaPosicaoX][determinaPosicaoY] != 0)
		{
			while(colisao[determinaPosicaoX][determinaPosicaoY] != 0)
			{	
				determinaPosicaoX = geraNumeroAleatorioX();
				determinaPosicaoY = geraNumeroAleatorioY();
			}
		}

		quadro[determinaPosicaoX][determinaPosicaoY] = '*';
		colisao[determinaPosicaoX][determinaPosicaoY] = 1;
	}
}

void geraObra2(char quadro[][COLUNAS], int qtdFiguras)
{
	int colisao[LINHAS][COLUNAS];
	int determinaPosicaoX;
	int determinaPosicaoY;

	for(int i = 0; i < LINHAS; i++)
	{
		for(int j = 0; j < COLUNAS; j++)
		{
			if(i == 0 || i == LINHAS-1) colisao[i][j] = 1;
			else if(j == 0 || j == COLUNAS-1) colisao[i][j] = 1;
			else colisao[i][j] = 0;
		}
	}

	for(int i = 0; i < qtdFiguras; i++)
	{
		determinaPosicaoX = geraNumeroAleatorioX();
		determinaPosicaoY = geraNumeroAleatorioY();
		//Garante que o * do centro não encostará na moldura e em posição já ocupada
		if(determinaPosicaoX <= 1 ||determinaPosicaoX <= LINHAS -2 ||determinaPosicaoY <= 1|| determinaPosicaoY <= COLUNAS -2
			||colisao[determinaPosicaoX][determinaPosicaoY] != 0 || colisao[determinaPosicaoX][determinaPosicaoY+1] != 0||
			colisao[determinaPosicaoX][determinaPosicaoY-1] != 0|| colisao[determinaPosicaoX+1][determinaPosicaoY] != 0||
			colisao[determinaPosicaoX-1][determinaPosicaoY]!=0)
		{
			while(colisao[determinaPosicaoX][determinaPosicaoY] != 0 || colisao[determinaPosicaoX+1][determinaPosicaoY] != 0 ||
			colisao[determinaPosicaoX-1][determinaPosicaoY]!=0 || colisao[determinaPosicaoX][determinaPosicaoY+1] != 0 ||
			colisao[determinaPosicaoX][determinaPosicaoY-1] != 0)
			{	
				determinaPosicaoX = geraNumeroAleatorioX();
				determinaPosicaoY = geraNumeroAleatorioY();
			}
		}

		quadro[determinaPosicaoX][determinaPosicaoY] = '*';
		quadro[determinaPosicaoX+1][determinaPosicaoY] = '*';
		quadro[determinaPosicaoX-1][determinaPosicaoY] = '*';
		quadro[determinaPosicaoX][determinaPosicaoY-1] = '*';
		quadro[determinaPosicaoX][determinaPosicaoY+1] = '*';

		colisao[determinaPosicaoX][determinaPosicaoY] = 1;
		colisao[determinaPosicaoX+1][determinaPosicaoY] = 1;
		colisao[determinaPosicaoX-1][determinaPosicaoY] = 1;
		colisao[determinaPosicaoX][determinaPosicaoY+1] = 1;
		colisao[determinaPosicaoX][determinaPosicaoY-1] = 1;
	}
}

void geraObra3(char quadro[][COLUNAS], int qtdFiguras)
{
	int colisao[LINHAS][COLUNAS];
	int determinaPosicaoX;
	int determinaPosicaoY;

	for(int i = 0; i < LINHAS; i++)
	{
		for(int j = 0; j < COLUNAS; j++)
		{
			if(i == 0 || i == LINHAS-1) colisao[i][j] = 1;
			else if(j == 0 || j == COLUNAS-1) colisao[i][j] = 1;
			else colisao[i][j] = 0;
		}
	}

	for(int i = 0; i < qtdFiguras; i++)
	{
		determinaPosicaoX = geraNumeroAleatorioX();
		determinaPosicaoY = geraNumeroAleatorioY();
		//Garante que o * do centro não encostará na moldura e em posição já ocupada
		if(determinaPosicaoX <= 1 ||determinaPosicaoX <= LINHAS -2 ||determinaPosicaoY <= 1|| determinaPosicaoY <= COLUNAS -2
			||colisao[determinaPosicaoX][determinaPosicaoY] != 0 || colisao[determinaPosicaoX-1][determinaPosicaoY+1] != 0||
			colisao[determinaPosicaoX-1][determinaPosicaoY-1] != 0|| colisao[determinaPosicaoX+1][determinaPosicaoY+1] != 0||
			colisao[determinaPosicaoX+1][determinaPosicaoY-1]!=0)
		{
			while(colisao[determinaPosicaoX][determinaPosicaoY] != 0 || colisao[determinaPosicaoX+1][determinaPosicaoY-1] != 0 ||
			colisao[determinaPosicaoX+1][determinaPosicaoY+1]!=0 || colisao[determinaPosicaoX-1][determinaPosicaoY+1] != 0 ||
			colisao[determinaPosicaoX-1][determinaPosicaoY-1] != 0)
			{	
				determinaPosicaoX = geraNumeroAleatorioX();
				determinaPosicaoY = geraNumeroAleatorioY();
			}
		}

		quadro[determinaPosicaoX][determinaPosicaoY] = '*';
		quadro[determinaPosicaoX+1][determinaPosicaoY-1] = '*';
		quadro[determinaPosicaoX+1][determinaPosicaoY+1] = '*';
		quadro[determinaPosicaoX-1][determinaPosicaoY-1] = '*';
		quadro[determinaPosicaoX-1][determinaPosicaoY+1] = '*';

		colisao[determinaPosicaoX][determinaPosicaoY] = 1;
		colisao[determinaPosicaoX+1][determinaPosicaoY-1] = 1;
		colisao[determinaPosicaoX+1][determinaPosicaoY+1] = 1;
		colisao[determinaPosicaoX-1][determinaPosicaoY+1] = 1;
		colisao[determinaPosicaoX-1][determinaPosicaoY-1] = 1;
	}
}

//Une as funções anteriores e de forma aleatória decide qual função vai ser chamada
void geraObraMisturada(char quadro[][COLUNAS], int qtdFiguras)
{
	int seletorDeObra = 0;
	for(int i = 0; i < qtdFiguras; i++)
	{
		seletorDeObra = rand()%(4);
		switch (seletorDeObra) {
			case 1:
				geraObra1(quadro, 1);
				break;
			case 2:
				geraObra2(quadro, 1);
				break;
			case 3:
				geraObra3(quadro, 1);
				break;
			default:
				break;
		}
	}
}

//Usada para auxiliar na correção das artes ASCII
//Evita seg fault e sobreposição de elementos
void contarLinhasColunas(pkm pkmn, int* linhas, int* colunas)
{
    *linhas = 0;
    *colunas = 0;
    int larguraAtual = 0;

    for (int i = 0; pkmn.img[i] != '\0'; i++)
    {
        if (pkmn.img[i] == '\n')
	{
            (*linhas)++;
            if (larguraAtual > *colunas)
	    {
                *colunas = larguraAtual;
            }
            larguraAtual = 0;
        }

	else
	{
            larguraAtual++;
        }
    }

    if (larguraAtual > 0)
    {
        (*linhas)++;
        if (larguraAtual > *colunas) {
            *colunas = larguraAtual;
        }
    }
}

//Desenha no quadro alguma das artes de forma aleatória
void geraObraPessoal(char quadro[][COLUNAS])
{
   
    pkm bulbasaur, ivysaur, venusaur;
    pkm squirtle, wartortle, blastoise;
    pkm charmander, charmeleon, charizard;
    
    bulbasaur.img = 
    "                                           /\n"
    "                        _,.------....___,.' ',.-.\n"
    "                     ,-'          _,.--\"        |\n"
    "                  /   ,     ,'                   `\n"
    "     .'    `---\"\"       ``\"-.--\"'`  \\               .  \\\n"
    "    .  ,            __               `              |   .\n"
    "   ,'          '    _.'                -._          /    |\n"
    "  ,`-.    ,\".   `--'                      >.      ,'     |\n"
    " . .'\\'   `-'       __    ,  ,-.         /  `.__.-      ,'\n"
    " ||:, .           ,'  ;  /  / \\ `        `.    .      .'/\n"
    " j|:D  \\          `--'  ' ,'_  . .         `.__, \\   , /\n"
    "/ L:_  |                 .  \"' :_;                `.'.'\n"
    ".    \"\"'                  \"\"\"\"\"'                    V\n"
    " `.                                 .    `.   _,..  `\n"
    "   `,_   .    .                _,-'/    .. `,'   __  `\n"
    "    ) \\`._        ___....----\"'  ,'   .'  \\ |   '  \\  .\n"
      " '-.__ __ _,','    '`-..___;-...__   ,.'\\ ____.___.'\n"
    " `\"^--'..'   '-`-^-\"'--    `-^-'`.''\"\"\"\"\"`.,^.`.--' mh\n";

    ivysaur.img =
        "                             ,'        Y',\"..\n"
        "                           ,'           \\  | \\\n"
        "                          /              . |  `\n"
        "       _   \\  `. ---.   |                | j    |\n"
        "      / `-._\\   `Y   \\  |                |.     |\n"
        "     _`.    ``    \\   \\ |..              '      |,-'\"\"7,....\n"
               "       `--,   _.-' `\".           /__ `'-.' '         .\n"
        "       ,---..._,.--\"\"\"\"\"\"--.__..----,-.'   .  /    .'   ,. --\n"
        "       |                          ,':| /    | /     ;.,-'--      ,.-\n"
        "     ,' `.   \\ ,'           _,     `''   ``.-'       `-  -..___,'\n"
        "    . ,.  .   `   __     .-'  _.-           `.     .__    \\\n"
        "    |. |`        \"  ;   !   ,.  |             `.    `.`'---'\n"
        "    ,| |C\\       ` /    | ,' |(]|            -. |-..--`\n"
        "   /  \"'--'       '      /___|__]        `.  `- |`.\n"
        "    \\                      .,-'  ,'         .     `-.\n"
        "     x---..`.  -'  __..--'\"/\"\"\"\"\"  ,-.      |   |   |\n"
        "    / \\--._'-.,.--'     _`-    _. ' /       |     -.| \n"
              "//\\   ,-._.'\"/\\__,.   _,\"     /_\\__/`. /'.-.'.-/_,`-' mh\n";

    venusaur.img =
        "                            _._       _,._\n"
        "                        _.'   `. ' .'   _`.\n"
        "                ,\"\"\"/`\"\"-.-.,/. ` V'\\-,`.,--/\"\"\".\"-..\n"
        "              ,'    `...,' . ,\\-----._|     `.   /   \\\n"
       
        " `---    /        /  / j'       _/|..`  -. `-`\\ \\   \\  \\   `.  \\ `-..\n"
        ",\" _.-' /    /` ./  /`_|_,-\"   ','|       `. | -'`._,   L  \\ .  `.   |\n"
        "`\"' /  /  / ,__...-----| _.,  ,'            `|----.._`-.|' |. .` ..  .\n"
        "   /  '| /.,/   \\--.._ `-,' ,          .  '`.'  __,., '  ''``._ \\ \\`,'\n"
        "   /       `.     ,  ..._ ' `_/ '| |\\ `._'       '-.'   `.,'     |\n"
        "  '         /    /  ..   `.  `./ | ; `.'    ,\"\" ,.  `.    \\      |\n"
        "   `.     ,'   ,'   | |\\  |       \"        |  ,'\\ |   \\    `    ,L\n"
        "   /|`.  /    '     | `-| '                  /`-' |    L    `._/  \\\n"
        "  / | .`|    |  .   `._.'                   `.__,'   .  |     |  (`\n"
        " '-\"\"-'_|    `. `.__,._____     .    _,        ____ ,-  j     \".-'\"'\n"
        "        \\      `-.  \\/.    `\"--.._    _,.---'\"\"\\/  \"_,.'     /-'\n"
        "         )        `-._ '-.        `--\"      _.-'.-\"\"        `.\n"
        "       /_\\.__,\"\".   ,.'  \"`-...________.---\"     .\".   ,.  / \\\n"
        "              \\_/\"\"\"-'                           `-'--(_,`\"`-` mh\n";
	
	squirtle.img = 
        "               _,........__\n"
        "            ,-'            \"`-.\n"
        "        ,'                        \\\n"
        "      ,'                           .\n"
        "      .'\\               ,\"\".       `\n"
        "     ._.'|             / |  `       \\\n"
        "     |   |            `-.'  ||       `.\n"
        "     |   |            '-._,'||       | \\\n"
        "     .`.,'             `..,'.'       , |`-.\n"
        "     l                       .'`.  _/  |   `.\n"
        "     `-.._'-   ,          _ _'   -\" \\  .     `\n"
        "`.\"\"\"\"\"'-.`-...,---------','         `. `....__.\n"
        ".'        `\"-..___      __,'\\          \\  \\     \\\n"
        "  `.          |              `.          |  .     L\n"
        "      `._    .'      |          `.     .|   ,     |\n"
        "         `--,\\       .            `7\"\"' |  ,      |\n"
        "            ` `      `            /     |  |      |    _,-'\"\"\"`-.\n"
        "                                  `---.__,--.'mh\n";

	wartortle.img = 
        " __                                _.--'\"7\n"
        "    `. `--._                        ,-'_,-  ,'\n"
        "     ,'  `-.`-.                   /' .'    ,|\n"
        "     `.     `. `-     __...___   /  /     - j\n"
        "       `.     `  `.-\"\"        \" .  /       /\n"
        "         \\     /                ` /       /\n"
        "          \\   /                         ,'\n"
        "          '._'_               ,-'       |\n"
        "             | \\            ,|  |   ...-'\n"
        "             || `         ,|_|  |   | `             _..__\n"
        "            /|| |          | |  |   |  \\  _,_    .-\"     `-.\n"
        "           | '.-'          |_|_,' __!  | /|  |  /           \\\n"
        "   ,-...___ .=                  ._..'  /`.| ,`,.      _,.._ |\n"
        "  |   |,.. \\     '  `'        ____,  ,' `--','  |    /      |\n"
        " ,`-..'  _)  .`-..___,---'_...._/  .'      '-...'   |      /\n"
        "'.__' \"\"'      `.,------'\"'      ,/            ,     `.._.' `.\n"
        "  `.             | `--........,-'.            .         \\     \\\n"
        "                                    `---'--.,'\"`' mh\n";


	blastoise.img = 
	"                          _\n"
	"            _,..-\"\"\"--' `,.-\".\n"
	"          ,'      __.. --',  |\n"
	"        _/   _.-\"' |    .' | |       ____\n"
	"  ,.-\"\"'    `-\"+.._|     `.' | `-..,',--.`.\n"
	" |   ,.                      '    j 7    l \\__\n"
	" |.-'                            /| |    j||  .\n"
	" `.                   |         / L.`\"\"','|\\  \\\n"
	"   `.,----..._       ,'`\"'-.  ,'   \\ `\"\"'  | |  l\n"
	"     Y        `-----'       v'    ,'`,.__..' |   .\n"
	"      `.                   /     /   /     `.|   |\n"
	"        `.                /     l   j       ,^.  |L\n"
	"          `._            L       +. |._   .' \\|  | \\\n"
	"            .`--...__,..-'\"\"'-._  l L  \"\"\"    |  |  \\\n"
	"          .'  ,`-......L_       \\  \\ \\     _.'  ,'.  l\n"
	"                 \"\"\"\"\"`.,'         _\\`----...' mh\n"
	"                        --------\"\"'\n";


	charmander.img = 
	"              _.--\"\"`-..\n"
	"            ,'          `.\n"
	"          ,'          __  `.\n"
	"         /|          \" __   \\\n"
	"        , |           / |.   .\n"
	"        |,'          !_.'|   |\n"
	"      ,'             '   |   |\n"
	"     /              |`--'|   |\n"
	"    |                `---'   |\n"
	"     .   ,                   |                       ,\".\n"
	"      ._     '           _'  |                    , ' \\ `\n"
	"  `.. `.`-...___,...---\"\"    |       __,.        ,`\"   L,|\n"
	"  |, `- .`._        _,-,.'   .  __.-'-. /        .   ,    \\\n"
	"-:..     `. `-..--_.,.<       `\"      / `.        `-/ |   .\n"
	"                            `\" \" -' mh\n";

	charmeleon.img = 
	"                  _,\"'    j\n"
	"           __....+       /               .\n"
	"       ,-\"'             /               ; `-._.'.\n"
	"      /                (              ,'       .'\n"
	"     |            _.    \\             \\   ---._ `-.\n"
	"     ,|    ,   _.'  Y    \\             `- ,'   \\   `.`.\n"
	"     l'    \\ ,'._,\\ `.    .              /       ,--. l\n"
	"  .,-        `._  |  |    |              \\       _   l .\n"
	" /              `\"--'    /              .'       ``. |  )\n"
	".\\    ,                 |                .        \\ `. '\n"
	"`.                .     |                '._  __   ;. \\'\n"
	"  `-..--------...'       \\                  `'  `-\"'.  \\\n"
	"      `......___          `._                        |  \\\n"
	"               /`            `..                     |   .\n"
	"              /|                `-.                  |    L\n"
	"             / |               \\   `._               .    |\n"
	"           ,'  |,-\"-.   .       .     `.            /     |\n"
	"                                        `.' mh\n";

	charizard.img = 
	"                 `.     `.  ,\n"
	"              .--'  .._,'\"-' `.\n"
	"             `.   /          ,'\n"
	"               `  '--.   ,-\"'\n"
	"                   -. \\, |\n"
	"                    `--Y.'      ___.\n"
	"                         \\     L._, \\\n"
	"               _.,        `.   <  <\\                _\n"
	"             ,' '           `, `.   | \\            ( `\n"
	"          ../, `.            `  |    .\\`.           \\ \\_\n"
	"         ,' ,..  .           _.,'    ||\\l            )  '\".\n"
	"        , ,'   \\           ,'.-.`-._,'  |           .  _._`.\n"
	"      ,' /      \\ \\        `' ' `--/   | \\          / /   ..\\\n"
	"    .'  /        \\ .         |\\__ - _ ,'` `        / /     `.`.\n"
	"    |  '          ..         `-...-\"  |  `-'      / /        . `.\n"
	"    | /           |L__           |    |          / /          `. `.\n"
	" / .           \\\"`_/. `-_ \\_,.  ,'    +-' `-'  _,        ..,-.    \\`.\n"
        " mh\n";

        pkm iniciaisKanto[] = {bulbasaur,ivysaur,venusaur,squirtle,wartortle,blastoise,charmander,charmeleon,charizard};
       
	//int l = 0;
	//int c = 0;
	//for(int i = 0; i < 9; i++)
	//{
	//	contarLinhasColunas(iniciaisKanto[i], &l, &c);
	//	printf("Linhas=%d\nColunas=%d\n",l,c);
	//}

	int seletorDePkm = 0;
	seletorDePkm = rand()%9;
	int linhas = 1;
	int colunas = 1;
	
	//Insere Pokémon escolhido no quadro de forma aleatória
	for(int j = 0; iniciaisKanto[seletorDePkm].img[j] != '\0'; j++)
	{
		if(iniciaisKanto[seletorDePkm].img[j] == '\n')
		{
			quadro[linhas][colunas] = '\0';
			linhas++;
			colunas = 1;
		}
		else
		{
			quadro[linhas][colunas] = iniciaisKanto[seletorDePkm].img[j];
			colunas++;
		}
	}
	quadro[linhas][colunas] = '\0';
}
