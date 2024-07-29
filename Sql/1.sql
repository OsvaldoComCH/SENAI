/*
Create Database Test;
Use Test;
Create Table Aluno
(
	IDAluno int primary key auto_increment,
    Nome Varchar(60) Not NULL,
    Sobrenome Varchar(60) Not NULL
);
Create Table Professor
(
	IDProfessor int primary key auto_increment,
    Nome Varchar(60) Not NULL,
    Sobrenome Varchar(60) Not NULL
);
Create Table Turma
(
	IDTurma int Primary Key auto_increment,
    IDAluno int,
    Foreign Key (IDAluno) References Aluno(IDAluno),
    IDProfessor int,
    Foreign Key (IDProfessor) References Professor(IDProfessor)
);
*/
