SELECT name FROM people
WHERE people.id IN
(SELECT DISTINCT stars.person_id
FROM stars JOIN movies on stars.movie_id = movies.id
WHERE movies.year = 2004)
ORDER BY birth;
