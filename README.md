Sistema de CDteca Pessoal em C

Projeto desenvolvido como parte dos estudos de programação em linguagem C para o gerenciamento de uma coleção de CDs/álbuns musicais. O sistema permite o controle completo do acervo, registro de reproduções, relatórios e buscas avançadas.

---

##  Funcionalidades do Sistema

O programa está dividido em três módulos principais:

*   **Módulo A (Gerenciamento de Acervo):**
    *   **Cadastrar Novo CD:** Adiciona novos álbuns ao sistema com ID gerado automaticamente, título, artista, gênero e ano de lançamento.
    *   **Listar Toda a Coleção:** Exibe todos os CDs cadastrados com seus respectivos detalhes e contador de reproduções.
    *   **Incrementar Reproduções:** Permite selecionar um álbum pelo ID para registrar que ele foi reproduzido ("ouvido"), aumentando seu contador.

*   **Módulo B (Relatórios e Buscas):**
    *   **Ranking de Mais Ouvidos:** Organiza e exibe os álbuns do mais ouvido para o menos ouvido utilizando o algoritmo *Bubble Sort*.
    *   **Filtrar por Gênero Musical:** Busca e lista todos os álbuns pertencentes a um gênero específico informado pelo usuário.
    *   **Buscar por Artista ou Título:** Realiza uma busca textual para localizar álbuns específicos na coleção.

*   **Módulo C (Menu Interativo):**
    *   Interface de usuário via terminal em formato de loop contínuo (`do-while` com `switch-case`) permitindo navegar livremente entre as opções até escolher sair.

---

##  Tecnologias Utilizadas

*   **Linguagem C**
*   **Manipulação de Structs e Vetores**
*   **Controle de Fluxo e Funções**

---
