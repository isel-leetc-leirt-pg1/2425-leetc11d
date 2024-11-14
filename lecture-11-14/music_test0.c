#include "music_db.h"

#include <stdio.h>
#include <string.h>
#include "music_db.h"



typedef int artist_id_t;
typedef int album_id_t;
typedef int track_id_t;
typedef int genre_id_t;

/*


typedef struct {
    album_id_t id;
    bool in_use;
    char name[MAX_ALBUM_NAME+1];
    date_t release_date;
    int n_tracks;
    track_id_t tracks[MAX_ALBUM_TRACKS];
    artist_id_t artist_id;
} album_t;

typedef struct {
    track_id_t id;
    bool in_use;
    char name[MAX_TRACK_NAME+1];
    int duration;   // duration in seconds
    album_id_t album_id;      
} track_t;

typedef struct {
    genre_id_t id;
    char name[MAX_GENRE_NAME+1];
} genre_t;

typedef struct {
    artist_id_t id;
    bool in_use;
    char name[MAX_ARTIST_NAME+1];
    int n_albums;
    album_id_t albums[MAX_ARTIST_ALBUMS];
    int popularity;    // índice de popularidade de 0 a 100
    genre_id_t genre_id ; // genero do artista
} artist_t;

*/


// globals


// genres
int db_ngenres = 2;
genre_t db_genres[MAX_GENRES] = {
    { .id = 0, .name = "pop" },
    { .id = 1, .name = "rock" }
};
       

// artists
int db_nartists = 2;
artist_t db_artists[MAX_ARTISTS] = {
    { .id = 0, .in_use = true, .name = "sting", 
      .n_albums = 1, .albums = { 0 }, .popularity = 80, .genre_id = 1 
    },
    { .id = 1, .in_use = true, .name = "benjamin clementine",
      .n_albums = 1, .albums = { 2}, .popularity = 70, .genre_id = 0
    }
    
};
/*
typedef struct {
    album_id_t id;
    bool in_use;
    char name[MAX_ALBUM_NAME+1];
    date_t release_date;
    int n_tracks;
    track_id_t tracks[MAX_ALBUM_TRACKS];
    artist_id_t artist_id;
} album_t;
*/

// albums
int db_nalbums = 1;
album_t db_albums[MAX_ALBUMS] = {
    { .id = 0, .in_use = true, .name = "soul cages", 
      .release_date = { .day = 1, .month = 1, .year = 1987 },
      .n_tracks = 0, .artist_id = 0
    },
    { .in_use = false },
    { .id = 2, .in_use = true, .name = "unknown",
       .release_date = { .day = 1, .month = 1, .year = 2023 },
       .n_tracks = 0, .artist_id = 1
   }
};
  

// tracks
int db_ntracks = 0;
track_t db_tracks[MAX_TRACKS];


int main() {
    db_dump();
}
