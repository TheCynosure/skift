#pragma once

/* Copyright © 2018-2019 N. Van Bossuyt.                                      */
/* This code is licensed under the MIT License.                               */
/* See: LICENSE.md                                                            */

typedef struct 
{

} image_decoder_t;

image_decoder_t png_decoder;
image_decoder_t jpg_decoder;
image_decoder_t  ff_decoder;

typedef struct 
{

} image_encoder_t;

image_encoder_t png_encoder;
image_encoder_t jpg_encoder;
image_encoder_t  ff_encoder;

void image_decode(image_decoder_t decoder);
void image_decode_auto();

void image_encode(image_encoder_t encoder);
void image_encode_auto();