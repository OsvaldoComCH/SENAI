Select Nome From tb_estudio;

Select Count(*) From tb_filmes group by AnoLancamento;

Select Count(*) as Quantidade, Nacionalidade From tb_atores 
Where Nacionalidade != 'Americana' 
group by Nacionalidade;

Select Nome From tb_filmes order by AnoLancamento desc limit 1;

Select Nome From tb_estudio Where FaturamentoAnoAnterior > 1000000;

Select Count(*) as Quantidade From tb_atores Where Idade < 30;

Select Avg(Meses) From tb_filmes;

Select tb_filmes.Nome From tb_filmes
Right Join tb_papel on tb_papel.IDFilme = tb_filmes.IDFilme
Order By tb_papel.CacheAtor Limit 1;

Select Nome From tb_filmes Where AnoLancamento > YEAR(CURRENT_DATE()) - 5;

Select Nome From tb_filmes order by AnoLancamento desc limit 1;

Select tb_estudio.Nome, Avg(CustoTotal) From tb_filmes 
Inner Join tb_estudio on tb_estudio.IDEstudio = tb_filmes.IDEstudio
Group By tb_estudio.IDEstudio;

Select Nome From tb_atores Where Idade > 40 And Nacionalidade = 'Brasileira';

Select Nome, CustoTotal From tb_filmes Order By CustoTotal;

Select Count(*) From tb_filmes Where CustoTotal Between 100 And 500;

Select Count(*) From tb_estudio Where FaturamentoAnoAnterior > 1000000 And DataFundacao < "2000-01-01";