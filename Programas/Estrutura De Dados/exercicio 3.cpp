//3.	Qual a diferença entre: 
//a.	*fim->próximo
//b.	(*fim)->próximo
//Você pode usar um código para explicação, mostre valores.
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

//*fim->proximo: Neste caso, a seta (->) tem precedência sobre o operador de desreferência (*). Isso significa que primeiro acessamos o campo proximo e depois desreferenciamos o valor nele contido.

//(*fim)->proximo: Usando parênteses para desreferenciar *fim, primeiro desreferenciamos o ponteiro fim e, em seguida, acessamos o campo proximo do nó apontado por fim