CREATE TABLE movies (
                    id INTEGER,
                    title TEXT NOT NULL,
                    year NUMERIC,
                    PRIMARY KEY(id)
                );
CREATE TABLE stars (
                movie_id INTEGER NOT NULL,
                person_id INTEGER NOT NULL,
                FOREIGN KEY(movie_id) REFERENCES movies(id),
                FOREIGN KEY(person_id) REFERENCES people(id)
            );
CREATE TABLE directors (
                movie_id INTEGER NOT NULL,
                person_id INTEGER NOT NULL,
                FOREIGN KEY(movie_id) REFERENCES movies(id),
                FOREIGN KEY(person_id) REFERENCES people(id)
            );
CREATE TABLE ratings (
                movie_id INTEGER NOT NULL,
                rating REAL NOT NULL,
                votes INTEGER NOT NULL,
                FOREIGN KEY(movie_id) REFERENCES movies(id)
            );
CREATE TABLE people (
                id INTEGER,
                name TEXT NOT NULL,
                birth NUMERIC,
                PRIMARY KEY(id)
            );
1.sql
SELECT count(title) FROM movies WHERE year = 2008

2.sql
SELECT birth FROM people WHERE name = 'Emma Stone'

3.sql
SELECT count(title) FROM movies WHERE year >= 2018 ORDER BY title

4.sql
SELECT count(movie_id) FROM ratings WHERE rating = 10

5.sql
SELECT count(title), year FROM movies WHERE lower(title) LIKE('harry potter%') ORDER BY year

6.sql
SELECT avg(rating) FROM ratings WHERE movie_id in (SELECT id FROM movies WHERE year = 2012)

7.sql
SELECT count(movies.title), ratings.rating
FROM movies JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.year = 2010
ORDER BY ratings.rating DESC, movies.title

8.sql
SELECT count(name) FROM people WHERE id IN
(SELECT person_id FROM stars WHERE movie_id = (SELECT id FROM movies WHERE title = 'Toy Story'))

9.sql
SELECT count(distinct name) FROM
people WHERE id IN (
SELECT person_id FROM stars WHERE movie_id IN (
SELECT id FROM movies WHERE year = 2004)) ORDER BY birth

10.sql
SELECT count(name) FROM people WHERE id IN (
SELECT person_id FROM directors WHERE movie_id  IN (
SELECT movie_id FROM ratings WHERE rating >= 9))

11.sql
SELECT movies.title
FROM movies JOIN ratings ON movies.id = ratings.movie_id
WHERE movie_id IN (SELECT movie_id from stars WHERE person_id = (
SELECT id FROM people WHERE name = 'Chadwick Boseman'))
ORDER BY ratings.rating DESC LIMIT(5)

12.sql
SELECT COUNT(*) FROM (
SELECT title FROM movies
WHERE id IN (SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Johnny Depp'))
INTERSECT
SELECT title FROM MOVIES
WHERE id IN (SELECT movie_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Helena Bonham Carter'))
)

13.sql
SELECT  COUNT(distinct name)
FROM    people
WHERE   id IN ( SELECT  person_id
                FROM    stars
                WHERE   movie_id in (	SELECT movie_id
                                    	FROM stars
                                    	WHERE person_id = ( 	SELECT id
                                                        	FROM people
                                                        	WHERE name = 'Kevin Bacon'
                                                        	AND birth = 1958)))
AND name != 'Kevin Bacon'