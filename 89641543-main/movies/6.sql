SELECT AVG(rating) AS Average_Rating
FROM ratings
WHERE movie_id IN (SELECT id FROM movies WHERE year = 2012);
