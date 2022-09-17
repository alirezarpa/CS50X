SELECT AVG(ALL energy) FROM songs WHERE songs.artist_id = (SELECT id FROM artists WHERE name = "Drake");
