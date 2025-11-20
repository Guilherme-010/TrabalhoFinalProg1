<h1>Trabalho de Implementação — VoidBank</h1>
<strong>Objetivo: consolidar conceitos de modularização, funções, vetores e structs.</strong>
<h2>Objetivo do Trabalho</h2>
<p>Implementar uma aplicação local, com interface textual, que simula uma conta bancária.
Cada operação bem-sucedida deve ser registrada em um vetor de 100 posições contendo
as transações realizadas. Ao atingir 100 transações, o sistema deve avisar e encerrar
automaticamente.</p>
<p>Operações disponíveis
<ul>
<li>1. Depositar (conta corrente)</li>
<li>2. Sacar (sem cheque especial)</li>
<li>3. Aplicar na poupança</li>
<li>4. Resgatar da poupança</li>
<li>5. Fazer PIX (registrar conta/chave de destino)</li>
<li>6. Consultar saldos</li>
<li>7. Extrato (listar transações com data/hora)</li>
<li>8. Sair</li>
<li>9. Rendimento mensal da poupança</li>
<li>10.Receber pix</li>
</ul>
Atenção: as operações 9 e 10 são iniciadas como consequência de eventos, e não por
escolha do usuário. Logo, elas não devem aparecer no menu de opções.</p>

<h2>Estrutura de dados</h2>
<p>Cada transação é registrada em um vetor fixo de 100 elementos (struct Transacao):
● tipo — enum (DEP, SAQ, APLI, RESG, PIX, REND)
● valor — valor da transação em centavos (long long)
● saldo_corrente_apos e saldo_poupanca_apos — valores respectivamente da
conta e da poupança após a transação
● destino — string (usada apenas em PIX)
● quando — data e hora no formato “YYYY-MM-DD HH:MM:SS”
Regras importantes
● O vetor possui capacidade fixa de 100 transações. Após a centésima, o sistema
imprime: [ALERTA] Capacidade de registros atingida (100 transações). O serviço
do VoidBank sairá do ar agora.
● Todas as operações válidas geram registro no log.
● Erros (valor inválido ou saldo insuficiente) não geram registro.
● O registro da data/hora deve ser obtido com uma função (ex: strftime, time,
localtime).</p>

Casos de teste mínimos
● Depósito seguido de consulta (verificar registro e data/hora).
● PIX com chave de destino (verificar campo destino).
● Saque acima do saldo (não gera registro).
● Fechar mês (gera REND com rendimento).
● Execução até 100 transações (gera aviso e encerra).
