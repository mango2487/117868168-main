SELECT name FROM people
JOIN movies ON movies.id = stars.movie_id
JOIN stars ON stars.person_id = people.id
WHERE movies.title = 'Toy Story';