# Requisitos para conseguir criar uma POC

- Visual Studio 2022
    - Necessário instalar o pacote de desenvolvimento para C++
- Instalação VCPKG <https://www.youtube.com/watch?v=VHzt6tH341o> 
- Instalação do Allegro5
    ```CMD
        vcpkg install allegro5
    ```

# Compilando projeto

> Não é necessário usar o Visual Studio para compilar a aplicação, mas é necessário ter instalado.

> É Recomendado utilizar o visual studio para compilar a aplicação, pelo gcc pode ocorrer problemas de import de libs. 

> Após instalação das dependências do projeto realize os seguintes passos:

# Utilizando VS Code:

- Instale o pack de extensão para __VSCode C/C++ Extension Pack__
- Tecle <kbd>F6</kbd> para compilar ou utilize o comando 
``` CMD
    gcc ./index.c -o ./output/
    ./output/index.exe 
```