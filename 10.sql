SELECT DISTINCT name FROM directors JOIN movies ON directors.movie_id = movies.id JOIN people on directors.person_id = people.id JOIN ratings on movies.id = ratings.movie_id where rating >= 9.0