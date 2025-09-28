#ifndef ANGORA_TAG_SET_H
#define ANGORA_TAG_SET_H
#include <stdint.h>
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct tag_seg {
  uint32_t begin;  // inclusive
  uint32_t end;    // exclusive
} tag_seg;

uint32_t __angora_tag_set_insert(uint32_t offset);

uint32_t __angora_tag_set_combine(uint32_t lb1, uint32_t lb2);

uint32_t __angora_tag_set_combine_n(const uint32_t *lbs, uint32_t size,
                                    bool infer_shape);

void __angora_tag_set_mark_sign(uint32_t lb);

void __angora_tag_set_infer_shape_in_math_op(uint32_t lb, uint32_t len);

void __angora_tag_set_combine_and(uint32_t lb);

void __angora_tag_set_fini();

/* NEW: enumerate segments for a label.
   If out==NULL or cap==0, returns the number of segments needed.
   Otherwise writes up to cap segments into out and still returns the total needed. */
size_t __angora_tag_set_find(uint32_t lb, struct tag_seg *out, size_t cap);


#ifdef __cplusplus
}
#endif

#endif
