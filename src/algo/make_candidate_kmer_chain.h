#ifndef __MAKE_CANDIDATE_KMER_CHAIN_H
#define __MAKE_CANDIDATE_KMER_CHAIN_H

#include "../corelib/gapped_candidate.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int qoff;
    int soff;
    int length;
} HbnKmerMatch;

typedef kvec_t(HbnKmerMatch) vec_hkm;

void
validate_hkm_list(HBN_LOG_PARAMS_GENERIC,
    const u8* read, 
    const u8* subject,
    const HbnKmerMatch* hkm_list,
    const int hkm_list_size);

void
make_candidate_kmer_chain(const HbnKmerMatch* hkma,
    const int hkmc,
    const int query_id,
    const int query_dir,
    const int query_size,
    const int subject_id,
    const int subject_size,
    const int max_kmer_dist,
    const double max_ddf,
    const int min_chain_score,
    vec_init_hit* init_hit_list);

#ifdef __cplusplus
}
#endif

#endif // __MAKE_CANDIDATE_KMER_CHAIN_H