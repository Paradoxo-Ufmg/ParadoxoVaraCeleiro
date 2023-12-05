# ParadoxoVaraCeleiro
O programa em questão é um código desenvolvido utilizando conceitos de calculo numérico para simular o paradoxo da vara e do celeiro da teoria da relatividade restrita.

Para que você possa utilizar esse programa, antes você terá que baixar o compilador da linguagem C, caso você esteja programando no Linux, você não precisa baixar
o compilador, pois o Linux já possui o compilador de forma nativa, caso você esteja utilizando o Windows você terá que baixar o compilador MinGw, você também terá que baixar um IDE, pode baixar a que você se sentir mais confortável.

Para o desenvolvimento do programa, foi optado pelo código modularizado, foi criado um arquivo com as funções e outro arquivo com o código principal.
No desenvolvimento do código foram criadas oito funções, foi criado duas funções que me retornam duas expressões algébricas, a primeira é para o fator de Lorentz 
que vai ser utilizada para calcular a contração do objeto, a segunda é a expressão para a velocidade, que vai ser usada para calcular a velocidade que um objeto
deveria ter dada uma contração.

As próximas três funções são as funções onde será aplicado os conceitos de cálculo numérico, no decorrer do código vai ser aplicado o método de Newton-Rapshon
para isso foi criado uma função que me gerá a função que vai ser utilizada nesse método, a próxima é a função que calcula a derivada dessa função, a derivada
foi calculado usando o método da diferença central, e por fim, foi criada a função que utiliza o método de Newton-Rapshon.

O método de Newton-Rapshon, é um método que calcula as raízes de uma função, mas como queremos calcular a raiz de uma expressão surgiu um problema,
pois dessa forma a variável na minha função deveria ser o fator de Lorentz, esse problema foi resolvido considerando a função com X² - A, sendo A a expressão
Desse forma quando calculado a raiz dessa expressão ela vai me retorna a raiz de A, esse é um método que pode ser usada para calcular a raiz de qualquer expressão.

As três funções seguintes, ficam sendo a função que calcula a velocidade para que um objeto tenha uma certa contração, a função que calcula a distorção sofrida pelo meu oobjeto, e a última função é uma função que mostra se existe ou não simulataneidade.

Para a criação dessa última função, foi medido o tempo em que a ponta direita da vara demora para chegar na porta direita do celeiro, e o tempo que a ponta esquerda
da vara demora para chegar na porta esquerda do celeiro, foi considerado que a distância entre os dois objetos eram de dez metros, o mesmo foi calculado, mas partindo
que o objeto que vai estar se movimentando é o celeiro e não a vara.
