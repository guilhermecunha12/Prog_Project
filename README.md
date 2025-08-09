# project_final 
Projeto realizado no âmbito da disciplina de Programação

# BÍBLIA DO GIT (holy shit):

## SE APARECER CONFLITO NO CLION OU ALGUMA COISA ESTRANHA NO TERMINAL, LIGAR CALL OU MANDAR MENSAGEM
## FAÇAM GIT STATUS EM TUDO!!!! PARA SABER O QUE ESTÁ A ACONTECER
## O QUE FAZER ANTES DE SUBMETER QUAISQUER MUDANÇAS NO BRANCH DE CADA UM

git checkout main

git pull origin main (Obtemos as mudanças mais recentes de main do GitHub)

git checkout nome do branch

git merge main, vai buscar as mudanças efetuadas em main

Fazer todas as mudanças

E só depois:
- git add .
- git commit -m "mensagem descritiva do que foi feito"

git push origin nome do branch para atualizar o novo conteúdo do branch no GitHub

git checkout main (Vai à main local)

git pull origin main && git merge nome do branch && git push origin main (os && são para executar os comandos ao mesmo tempo para evitar problemas com pushes e pulls simultâneos)

Explicações:

- git pull origin main (Ir buscar eventuais alterações à main remota que foram feitas enquanto fazíamos as nossas alterações locais para garantir que fazemos o push correto e atualizado)

- git merge nome do branch (dentro do main)

- git push origin main (Atualizar a main do GitHub)

# Esta imagem ajuda a exemplificar como funcionam os comandos mas o melhor é seguir o guia SEMPRE
  ![1710155247237](https://github.com/user-attachments/assets/48dc6ac0-eba1-4347-9cbd-0e5cf4e84bd0)



# 📌 Projeto de Programação — Manipulação de Imagens RGB em C++

Este projeto foi desenvolvido no âmbito da unidade curricular **Programação (L.EIC009)** e consiste na criação de um programa em **C++** para manipulação de imagens RGB (8 bits para cada cor) utilizando scripts na linguagem **Scrim**.

---

## 🎯 Objetivos
- Implementar as classes:
  - **`prog::Color`** — representação de cores RGB.
  - **`prog::Image`** — representação de imagens compostas por pixels `Color`.
  - **`prog::Command`** — comandos de manipulação de imagens em Scrim.
- Acrescentar comandos personalizados para transformação de imagens.
- Permitir leitura e escrita de imagens no formato **PNG**.
- Validar o código através de testes automáticos (previamente efetuada)

---

## 🖥️ Programas gerados
- **`runscrim`** → executa scripts Scrim.
- **`tester`** → executa testes automáticos para validação do código.

---

## 📂 Estrutura do projeto

### O que foi alterado/implementado:
- `include/Color.hpp`, `src/Color.cpp`
- `include/Image.hpp`, `src/Image.cpp`
- `include/Command.hpp`, `src/Command.cpp`
- `include/ScrimParser.hpp`, `src/ScrimParser.cpp`
- Pastas `include/Command/` e `src/Command/` (novos comandos)
- Pasta `output/` (imagens geradas, que serão comparadas posteriormente no tester de modo a comparar com o output esperado)

### O que não podia ser alterado/já estava completamente implementado:
- `main/RunScrim.cpp`, `main/Tester.cpp`
- `include/Scrim.hpp`, `src/Scrim.cpp`
- `include/PNG.hpp`, `src/PNG.cpp`
- Biblioteca `stb` (suporte a PNG)
- Diretórios `input/` e `expected/` (ficheiros de teste)

---

## 🔧 Funcionalidades implementadas pelo grupo

### 1. Classe Color
- Representa uma cor RGB com métodos para ler e alterar cada canal (0–255).

### 2. Classe Image
- Armazena largura, altura e pixels da imagem.
- Permite aceder e modificar pixels por coordenadas.

### 3. Novos comandos Scrim
- **Manipulação simples:**  
  `invert`, `to_gray_scale`, `replace`, `fill`, `h_mirror`, `v_mirror`, `add`, `move`, `slide`.
- **Alteração de dimensões:**  
  `crop`, `resize`, `rotate_left`, `rotate_right`, `scaleup`.

### 4. Funcionalidade avançada
- **`chain`** → executa múltiplos scripts Scrim de forma sequencial, com suporte a recursão controlada.

---

## 📜 Exemplo de script Scrim
```plaintext
blank 750 380 0 0 0
fill 0 0 250 380 255 0 0
add input/lion.png 255 255 255 0 0
save output/example.png
