CREATE DATABASE IF NOT EXISTS bookstore;
USE bookstore;


-- Tabela 'autores'
CREATE TABLE autores (
	autor_id INT AUTO_INCREMENT PRIMARY KEY,
	nome VARCHAR(100)
);


-- Tabela 'livros'
CREATE TABLE livros (
	livro_id INT AUTO_INCREMENT PRIMARY KEY,
	titulo VARCHAR(200),
	autor_id INT,
	preco DECIMAL(10, 2),
	FOREIGN KEY (autor_id) REFERENCES autores(autor_id)
);


-- Tabela 'clientes'
CREATE TABLE clientes (
	cliente_id INT AUTO_INCREMENT PRIMARY KEY,
	nome VARCHAR(100),
	email VARCHAR(100)
);
-- Tabela 'pedidos'
CREATE TABLE pedidos (
	pedido_id INT AUTO_INCREMENT PRIMARY KEY,
	cliente_id INT,
	livro_id INT,
	quantidade INT,
	data_pedido DATE,
	FOREIGN KEY (cliente_id) REFERENCES clientes(cliente_id),
	FOREIGN KEY (livro_id) REFERENCES livros(livro_id)
);

INSERT INTO autores (nome) VALUES
	('Stephen King'),
	('J.K. Rowling'),
	('George Orwell'),
	('Harper Lee'),
	('Agatha Christie'),
	('Gabriel García Márquez'),
	('Jane Austen'),
	('F. Scott Fitzgerald'),
	('Leo Tolstoy'),
	('J.R.R. Tolkien'),
	('Ernest Hemingway'),
	('Mark Twain'),
	('Charles Dickens'),
	('Herman Melville'),
	('Emily Brontë'),
	('Arthur Conan Doyle'),
	('Victor Hugo'),
	('Franz Kafka'),
	('Mary Shelley'),
	('Toni Morrison');
    
    
-- Inserções para a tabela 'livros'
INSERT INTO livros (titulo, autor_id, preco) VALUES
	('It', 1, 25.99),
	('Harry Potter and the Philosopher''s Stone', 2, 22.50),
	('1984', 3, 18.75),
	('To Kill a Mockingbird', 4, 20.80),
	('Murder on the Orient Express', 5, 16.99),
	('One Hundred Years of Solitude', 6, 21.25),
	('Pride and Prejudice', 7, 15.50),
	('The Great Gatsby', 8, 14.99),
	('War and Peace', 9, 29.99),
	('The Hobbit', 10, 17.95),
	('The Old Man and the Sea', 11, 12.75),
	('The Adventures of Huckleberry Finn', 12, 13.50),
	('Great Expectations', 13, 16.25),
	('Moby-Dick', 14, 19.99),
	('Wuthering Heights', 15, 14.50),
	('The Adventures of Sherlock Holmes', 16, 11.99),
	('Les Misérables', 17, 28.50),
	('The Metamorphosis', 18, 10.75),
	('Frankenstein', 19, 13.99),
	('Beloved', 20, 15.25);
    
    
-- Inserções para a tabela 'clientes'
INSERT INTO clientes (nome, email) VALUES
	('João Silva', 'joao.silva@example.com'),
	('Maria Santos', 'maria.santos@example.com'),
	('Pedro Oliveira', 'pedro.oliveira@example.com'),
	('Ana Pereira', 'ana.pereira@example.com'),
	('Carlos Souza', 'carlos.souza@example.com'),
	('Juliana Costa', 'juliana.costa@example.com'),
	('Lucas Martins', 'lucas.martins@example.com'),
	('Mariana Almeida', 'mariana.almeida@example.com'),
	('Gustavo Lima', 'gustavo.lima@example.com'),
	('Camila Rocha', 'camila.rocha@example.com'),
	('Fernando Gomes', 'fernando.gomes@example.com'),
	('Amanda Santos', 'amanda.santos@example.com'),
	('Rafael Pereira', 'rafael.pereira@example.com'),
	('Larissa Oliveira', 'larissa.oliveira@example.com'),
	('Diego Costa', 'diego.costa@example.com'),
	('Patrícia Souza', 'patricia.souza@example.com'),
	('Bruno Lima', 'bruno.lima@example.com'),
	('Carolina Alves', 'carolina.alves@example.com'),
	('Vinícius Fernandes', 'vinicius.fernandes@example.com'),
	('Marina Ribeiro', 'marina.ribeiro@example.com');
    
    
-- Inserções para a tabela 'pedidos'
INSERT INTO pedidos (cliente_id, livro_id, quantidade, data_pedido) VALUES
	(1, 1, 2, '2024-03-01'),
	(2, 2, 1, '2024-03-02'),
	(3, 3, 3, '2024-03-03'),
	(4, 4, 1, '2024-03-04'),
	(5, 5, 2, '2024-03-05'),
	(6, 6, 1, '2024-03-06'),
	(7, 7, 2, '2024-03-07'),
	(8, 8, 1, '2024-03-08'),
	(9, 9, 3, '2024-03-09'),
	(10, 10, 1, '2024-03-10'),
	(11, 11, 2, '2024-03-11'),
	(12, 12, 1, '2024-03-12'),
	(13, 13, 2, '2024-03-13'),
	(14, 14, 1, '2024-03-14'),
	(15, 15, 3, '2024-03-15'),
	(16, 16, 1, '2024-03-16'),
	(17, 17, 2, '2024-03-17'),
	(18, 18, 1, '2024-03-18'),
	(19, 19, 2, '2024-03-19'),
	(20, 20, 1, '2024-03-20');