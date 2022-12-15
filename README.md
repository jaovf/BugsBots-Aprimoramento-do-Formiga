# BugsBots-Aprimoramento-do-Formiga
  Projeto de SAA0356 - Sistemas Embarcados para Veículos Aéreos 2022.2
  
  Ministrante: Prof. Dr. Glauco Augusto de Paula Caurin
  
  Departamento de Engenharia Aeronáutica

<img src="./Imagens/identidade_visual_novo_logo.png" align="right"
     alt="Logo EESC" height="200">


## Alunos:
* **Caique Augusto Cerqueira Dioceser** *N° USP: 11232264* 
* **Cristina Luciana Rodrigues Saraiva Leão** *N° USP: 10716696* 
* **João Vítor Viana Falcão** *N° USP: 11232413* 
* **Laura Queiroz Soares** *N° USP: 11372625* 
* **Natthan Wictor de Camargo** *N° USP: 11352702* 


# Introdução
Estima-se que existam cerca de 18.000 espécies de formigas no mundo, ao final deste será possível dizer que existe uma espécie nova de formiga, a robótica. Por meio de softwares e hardwares computacionais e mecatrônicos foi desenvolvido um robô de seis pernas capaz de se locomover de forma autônoma. A razão para o desenvolvimento de um robô hexapode é sua facilidade de locomoção em terrenos irregulares, se mantendo mais estável do que em comparação com dispositívos de aplicação parecidas compostos por rodas.

## Objetivo
Desenvolver o acionamento e coordenação de múltiplos servo atuadores de aeromodelismo para implementação do padrão de caminhada para um robô de seis pernas.

## Material e Método
Utilizou-se um sistema de hardware, o qual consiste em uma placa Toradex Colibri VF61 embarcada na Viola Carrier Board e dois microcontroladores MBED LPC1768. Já o sistema operacional foi o Linux e a linguagem de programação Python. Além disso, foram usados dois servos motores em cada perna, totalizando doze (12).

Para a implementação, foram utilizadas saídas PWM, informando as posições dos servos, por meio da comunicação serial faz com que os dois microcontroladores se cominuquem da Toradex para os MBEDs conectados aos motores. A principal vantagem da comunicação serial é a diminuição dos gastos para que o sistema continue funcionando. Além disso, a transmissão de dados acontece de forma simplificada, onde é utilizado apenas um canal de comunicação.


<p align="center">
<img src="./Imagens/Módulo Colibri VF61.jpeg" width ="405" >
<img src="./Imagens/Placa Viola e MicroSD.jpeg" width="300">
</p>

<p align="center">
<img src="./Imagens/Placa Viola.jpeg" width ="355" >
<img src="./Imagens/Mbed.jpg" width="350">
</p>

# Desenvolvimento
## Lógica

## Código

## Comunicação


# Resultados







https://user-images.githubusercontent.com/119769311/207929898-81dae449-8cf5-42a6-8e74-0f024d8560f7.mp4



# Conclusão
Apesar do projeto ter sido bem sucedido, vale ressaltar que a comunicação serial não fazia parte da ideia inicial, uma vez que ao se trabalhar com MBEDs é melhor usar o protocolo CAN para a comunicação, visto que permite que outros dispositivos sejam conectados na mesma rede. Contudo, conforme já apontado, não foi possível a implementação dessa comunicação devido a falta de experiência da equipe com um protocolo tão robusto juntamente com o tempo limitado para tal. Portanto, optou-se pela comunicação serial, por sua simplicidade, permitindo a feitura do projeto proposto e dando a oportunidade de trabalhar com sistemas embarcados, logo, pode-se afirmar que o objetivo acadêmico da disciplina foi alcançado.
