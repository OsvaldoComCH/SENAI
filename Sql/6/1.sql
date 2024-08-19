-- Criação do banco de dados
DROP DATABASE IF EXISTS DetranDB;
CREATE DATABASE DetranDB;
USE DetranDB;

-- Tabela para registrar proprietários
CREATE TABLE Proprietarios (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(255) NOT NULL,
    cpf VARCHAR(11) UNIQUE NOT NULL,
    endereco VARCHAR(255),
    telefone VARCHAR(20),
    pontos_carteira INT DEFAULT 0
);

-- Tabela para registrar veículos
CREATE TABLE Veiculos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    marca VARCHAR(255) NOT NULL,
    modelo VARCHAR(255) NOT NULL,
    placa VARCHAR(7) UNIQUE NOT NULL,
    ano INT,
    proprietario_id INT,
    FOREIGN KEY (proprietario_id) REFERENCES Proprietarios(id)
);

-- Tabela para registrar infrações de trânsito
CREATE TABLE Infracoes (
    id INT AUTO_INCREMENT PRIMARY KEY,
    descricao VARCHAR(255) NOT NULL,
    gravidade ENUM('Leve', 'Média', 'Grave', 'Gravíssima'),
    data_ocorrencia DATE NOT NULL,
    veiculo_id INT,
    FOREIGN KEY (veiculo_id) REFERENCES Veiculos(id)
);

-- Tabela para registrar licenciamentos dos veículos
CREATE TABLE Licenciamentos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    data_validade DATE NOT NULL,
    veiculo_id INT,
    FOREIGN KEY (veiculo_id) REFERENCES Veiculos(id)
);

-- Tabela para registrar multas aplicadas
CREATE TABLE Multas (
    id INT AUTO_INCREMENT PRIMARY KEY,
    valor DECIMAL(10, 2) NOT NULL,
    pontos INT DEFAULT 0,
    data_aplicacao DATE NOT NULL,
    infracao_id INT,
    FOREIGN KEY (infracao_id) REFERENCES Infracoes(id)
);

Create Table Logs 
(
	id int primary key auto_increment,
    mensagem varchar(254) not NULL,
    datahora datetime not null default current_timestamp
);

-- Inserção de dados nas tabelas
-- Proprietarios
INSERT INTO Proprietarios (nome, cpf, endereco, telefone) VALUES
('João Silva', '12345678901', 'Rua A, 123', '(11) 1234-5678'),
('Maria Oliveira', '98765432101', 'Rua B, 456', '(11) 9876-5432'),
('Carlos Souza', '11122233344', 'Rua C, 789', '(11) 1111-2222'),
('Ana Lima', '55566677788', 'Rua D, 1011', '(11) 5555-6666'),
('Pedro Costa', '99988877766', 'Rua E, 1213', '(11) 9999-8888');

-- Veiculos
INSERT INTO Veiculos (marca, modelo, placa, ano, proprietario_id) VALUES
('Fiat', 'Uno', 'ABC1234', 2020, 1),
('Volkswagen', 'Gol', 'DEF5678', 2018, 2),
('Chevrolet', 'Onix', 'GHI9101', 2021, 3),
('Ford', 'Ka', 'JKL1112', 2019, 4),
('Honda', 'Civic', 'MNO1314', 2022, 5),
('Toyota', 'Corolla', 'PQR1516', 2020, 1),
('Hyundai', 'HB20', 'STU1718', 2017, 2),
('Renault', 'Kwid', 'VWX1920', 2018, 3),
('Nissan', 'Versa', 'YZA2122', 2019, 4),
('Jeep', 'Compass', 'BCD2324', 2021, 5);

-- Infracoes
INSERT INTO Infracoes (descricao, gravidade, data_ocorrencia, veiculo_id) VALUES
('Excesso de velocidade', 'Média', '2024-04-20', 1),
('Estacionamento irregular', 'Leve', '2024-04-21', 2),
('Ultrapassagem em local proibido', 'Grave', '2024-04-22', 3),
('Falta de cinto de segurança', 'Leve', '2024-04-23', 4),
('Dirigir sob efeito de álcool', 'Gravíssima', '2024-04-24', 5),
('Uso de celular ao volante', 'Média', '2024-04-25', 6),
('Não respeitar a sinalização', 'Grave', '2024-04-26', 7),
('Estacionamento em vaga de idoso', 'Leve', '2024-04-27', 8),
('Falta de inspeção veicular', 'Grave', '2024-04-28', 9),
('Excesso de lotação', 'Média', '2024-04-29', 10);

-- Licenciamentos
INSERT INTO Licenciamentos (data_validade, veiculo_id) VALUES
('2024-04-30', 1),
('2023-05-01', 2),
('2023-05-02', 3),
('2024-05-03', 4),
('2023-05-04', 5),
('2024-05-05', 6),
('2025-05-06', 7),
('2012-05-07', 8),
('2022-05-08', 9),
('2008-05-09', 10);

-- Multas
INSERT INTO Multas (valor, pontos, data_aplicacao, infracao_id) VALUES
(150.00, 5, '2024-04-20', 1),
(100.00, 3, '2024-04-21', 2),
(500.00, 7, '2024-04-22', 3),
(80.00, 2, '2024-04-23', 4),
(2000.00, 10, '2024-04-24', 5),
(130.00, 4, '2024-04-25', 6),
(500.00, 7, '2024-04-26', 7),
(50.00, 2, '2024-04-27', 8),
(250.00, 6, '2024-04-28', 9),
(120.00, 4, '2024-04-29', 10);

/*
Inserir um novo veículo e seu proprietário (com trigger)
*/
Delimiter //
Create Procedure InsertVeiculo(marca VARCHAR(255), modelo VARCHAR(255), placa VARCHAR(7), ano INT, proprietario_id INT)
Begin
    INSERT INTO Veiculos (marca, modelo, placa, ano, proprietario_id) VALUES (marca, modelo, placa, ano, proprietario_id);
End;
// Delimiter ;
/*
Deletar um veículo e suas multas associadas (com trigger)
*/
Delimiter //
Create Procedure DeleteVeiculo(id_veiculo int)
Begin
	delete From Multas where id_infracao = (Select id_infracao from infracoes where id_veiculo = id_veiculo);
    Delete From Infracoes where id_veiculo = id_veiculo;
    Delete From Veiculos where id = id_veiculo;
End;
// Delimiter ;
/*
Inserir uma nova infração e atualizar multas associadas (com trigger)
*/
Delimiter //
Create Procedure InsertMulta(id_veiculo int, data date, pontos int, descricao varchar(100), gravidade Varchar(20), valor float)
Begin
	insert into Infracoes(descricao, gravidade, data_ocorrencia, veiculo_id) values (descricao, gravidade, data, id_veiculo);
	iNSERT INTO Multas (valor, pontos, data_aplicacao, infracao_id) VALUES (valor, pontos, data, (Select id_infracao from infracoes where id = id_veiculo));
End;
// Delimiter ;
/*
Atualizar pontos na carteira de um proprietário específico que levou uma multa(com trigger)
*/
Delimiter //

// Delimiter ;
/*
Deletar um proprietário e seus veículos associados (com trigger)
*/
Delimiter //

// Delimiter ;
/*
Selecionar veículos com licenciamento expirado
*/
Delimiter //
Create Procedure SelectLicenciamento()
Begin
	select veiculos.* from veiculos inner join licenciamentos on licenciamentos.id_veiculo = veiculos.id where licenciamentos.data_validade < Curdate();
End;
// Delimiter ;
/*
Selecionar veículos que possuem multas graves
*/
Delimiter //
Create Procedure SelectMultasGraves()
Begin
	select veiculos.* from veiculos inner join infracoes on infracoes.id_veiculo = veiculos.id where infracoes.gravidade = "Grave";
End;
// Delimiter ;
/*
Selecionar veículos acima de 2021 
*/
Delimiter //
Create Procedure Select2021()
Begin
	select veiculos.* from veiculos where infracoes.gravidade = "Grave";
End;
// Delimiter ;
/*
Selecionar multas de veículos abaixo de 2020
*/
Delimiter //

// Delimiter ;
/*
Selecionar todos os veículos com multas pendentes
*/
Delimiter //

// Delimiter ;
/*
Inserir um novo proprietário
*/
Delimiter //

// Delimiter ;
/*
Atualizar informações de um proprietário
*/
Delimiter //

// Delimiter ;
/*
Deletar um proprietário
*/
Delimiter //

// Delimiter ;
/*
Selecionar todos os proprietários
*/
Delimiter //

// Delimiter ;
/*
Inserir uma nova infração
*/
Delimiter //

// Delimiter ;
/*
Atualizar informações de uma infração
*/
Delimiter //

// Delimiter ;
/*
Deletar uma infração
*/
Delimiter //

// Delimiter ;
/*
Selecionar todas as infrações
*/
Delimiter //

// Delimiter ;
/*
Inserir um novo licenciamento
*/
Delimiter //

// Delimiter ;
/*
Atualizar informações de um licenciamento
*/
