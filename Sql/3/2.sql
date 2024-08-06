Use bookstore;

Select * From livros Inner Join autores on autores.autor_id = livros.autor_id;
Select * From livros Left Join autores on autores.autor_id = livros.autor_id;
Select * From livros Right Join autores on autores.autor_id = livros.autor_id;
/*
Select * From Livros;

Select * From Autores;
*/
Select * From Pedidos
Inner Join Clientes on Clientes.Cliente_id = Pedidos.Cliente_id
Inner Join Livros on Livros.Livro_id = Pedidos.Livro_id;

Select * From Pedidos
Inner Join Clientes on Clientes.Cliente_id = Pedidos.Cliente_id
Where data_pedido = "2024-03-12";

Select * From Livros
Right Join Pedidos on Pedidos.Livro_id = Livros.Livro_id
Inner Join Clientes on Clientes.Cliente_id = Pedidos.Cliente_id;

Select * From Clientes
Full Join Pedidos -- on Pedidos.Cliente_id = Clientes.Cliente_id
Where Pedidos.Cliente_id = NULL;

Select * From Autores
Inner Join Livros on Livros.Autor_id = Autores.Autor_id
Where Livros.Preco > 20;

Select * From livros Inner Join autores on autores.autor_id = livros.autor_id;

Select * From Livros
Right Join Pedidos on Pedidos.Livro_id = Livros.Livro_id
Inner Join Clientes on Clientes.Cliente_id = Pedidos.Cliente_id;

Select Autores.Nome From Autores
Inner Join Livros on Livros.Autor_id = Autores.Autor_id
Inner Join Pedidos on Pedidos.Livro_id = Livros.Livro_id
Where Livros.Preco != NULL
Group By Livros.Livro_id
Having Count(Pedidos.Pedido_id) > 1;

Select * From Clientes
Right Join Pedidos on Clientes.Cliente_id = Pedidos.Cliente_id
Inner Join Livros on  Pedidos.Livro_id = Livros.Livro_id;

Select * From Autores
Inner Join Livros on Livros.Autor_id = Autores.Autor_id
Inner Join Pedidos on Pedidos.Livro_id = Livros.Livro_id
Where data_pedido = "2024-03-12";

Select * From Clientes
Right Join Pedidos on Clientes.Cliente_id = Pedidos.Cliente_id
Inner Join Livros on  Pedidos.Livro_id = Livros.Livro_id
Where Clientes.Nome Like "A%";

Select * From Livros
Right Join Pedidos on Pedidos.Livro_id = Livros.Livro_id
Where Pedidos.Livro_id = NULL;