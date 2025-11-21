#include <stdio.h>
#include "conta.h"
#include "conta.c"

int main(void){
    transacao TransacaoAtual;
    conta ContaAtualDoUsuario;
    ContaAtualDoUsuario.saldo_corrente = 0;
    ContaAtualDoUsuario.saldo_poupanca = 0;
    int opcao = 0;
    while (opcao != 8){
        printf("1. Depositar (conta corrente)\n2. Sacar(Sem cheque especial)\n3. Aplicar\n4. Resgatar\n5. Fazer PIX\n6. Consultar saldos\n7.Extratos (Listar transacoes com data e hora)\n 8. Sair");
        printf("Digite o numero da opcao que correspondente desejada.\n");
        scanf("%d", opcao);
    }
}
