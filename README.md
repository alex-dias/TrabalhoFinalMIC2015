# Esteira GENOMAX

Alexandre Dias Negretti       558214
Igor Felipe Gallon            558320


A Esteira GENOMAX foi implementada utilizando o Arduino MEGA 2560 e verifica automaticamente se as peças manufaturadas estão vindo pela esteira. Caso não seja detectada nenhuma peça passando pela esteira durante 5 segundos, a esteira para e alerta sobre o ocorrido voltando a funcionar depois que uma peça for colocada no local indicado da esteira.
  
A detecção de peça é feita com um LED apontado para um sensor fotorresistivo (a passagem da peça interrompe a luz do LED incidente no sensor fotorresistivo acusando a presença da peça). O motor utilizado para mover a esteira é um Motor de Passo Modelo 23LM-C309 em conjunto com um CI Driver ULN2003. A esteira conta com um botão de On/Off e um sinalizador buzzer, além de um Display LCD que mostra o estado atual da esteira ("Em funcionamento" quando a esteira opera normalmente e "Inserir peça!" quando não houve detecção de peça durante 5 segundos).

No final, um Servomotor trabalha como atuador para retirar a peça da esteira, que será movida para o próximo estágio da produção. É acionado após a passagem da peça pelo sensor de presença.

## Esquemático

O esquemático do projeto encontra-se [aqui](http://www.schematics.com/project/labmic-24474/)

![Esquemático feito no schematics.com](http://i.imgur.com/FVYdR2a.png)
Esquemático feito no schematics.com

## Imagens do Projeto

![Esteira desligada.](http://i.imgur.com/lSvQV8s.jpg?2)
Esteira desligada.

![Esteira em funcionamento normal.](http://i.imgur.com/ZtodpXN.jpg?2)
Esteira em funcionamento.

![Esteira parada, esperando a peça.](http://i.imgur.com/knXbm8Y.jpg?2)
Esteira parada, esperando a peça.

##Clique na imagem para ver o vídeo demonstrativo de funcionamento:

[![IMAGE ALT TEXT HERE](http://i.imgur.com/lSvQV8s.jpg?2)](https://youtu.be/xlMNOnxL8Pw)

## Outros trabalhos desta disciplina

https://github.com/Power041/cancela

https://github.com/jblsouza/Lab-Mic-A

https://github.com/iksmada/TuringMachine

https://github.com/Fonseka100/MIC-Amaciante

https://github.com/matheusvervloet/girassolar

https://github.com/alex-dias/TrabalhoFinalMIC2015

https://github.com/gustavocesarlos/trabalhofinalMic

https://github.com/gabrielNT/LabMicApl_TrabalhoFinal

https://github.com/brunowilliamsap/microcontroladores

https://github.com/rodrigoa1990/Projeto-Microcontroladores

https://github.com/matheusDeAlmeida/trabalhoFinalMicrocontroladores

