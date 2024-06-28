SELECT DISTINCT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON s.movie_id = m.id
JOIN stars kb ON m.id = kb.movie_id
JOIN people kp ON kb.person_id = kp.id
WHERE kp.name = 'Kevin Bacon' AND kp.birth = 1958
  AND p.name != 'Kevin Bacon';
