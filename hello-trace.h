#undef TRACE_SYSTEM
#define TRACE_SYSTEM simul

#if !defined(_SIMUL_TRACE_H) || defined(TRACE_HEADER_MULTI_READ)
#define _SIMUL_TRACE_H

#include <linux/tracepoint.h>

TRACE_EVENT(me_simul,

    TP_PROTO(unsigned long time, unsigned long count),

	TP_ARGS(time, count),

	TP_STRUCT__entry(
        __field(unsigned long, time)
        __field(unsigned long, count)
    ),
	
	TP_fast_assign(
        __entry->time = jiffies;
        __entry->count = count;
    ),
    
	TP_printk("time=%lu count=%lu", __entry->time, __entry->count)
);


#endif
#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH .
#define TRACE_INCLUDE_FILE hello-trace
#include <trace/define_trace.h>


#if 0
#ifndef _SIMUL_RBTREE_H
#define _SIMUL_RBTREE_H

#define SIMUL_RB_RED		0
#define SIMUL_RB_BLACK	1
#define SIMUL_INIT_KEY	-1
#define SIMUL_RB_NIL		-2
#define SIMUL_RB_NOT_EXIST	-3

typedef struct simul_rb_node {
	uint8_t rb_color;
	uint64_t rb_key;
	struct simul_rb_node *rb_parent;
	struct simul_rb_node *rb_right;
	struct simul_rb_node *rb_left;
} simul_rb_node;

typedef struct simul_rb_root {
	simul_rb_node *root_node;
	simul_rb_node *nil_node;
} simul_rb_root;

simul_rb_node *parent_of (simul_rb_node *node);
simul_rb_node *right_of (simul_rb_node *node);
simul_rb_node *left_of (simul_rb_node *node);

void init_rb_node (simul_rb_root *T, simul_rb_node *node, uint64_t key);
void init_rb_root (simul_rb_root *root);

uint32_t is_rb_black (simul_rb_node *node);
uint32_t is_rb_red (simul_rb_node *node);

void set_rb_black (simul_rb_node *node);
void set_rb_red (simul_rb_node *node);

simul_rb_root *simul_rb_alloc_root (void);
void simul_free (simul_rb_node *node);
uint32_t simul_rb_left_rotate (simul_rb_root *T, simul_rb_node *node);
uint32_t simul_rb_right_rotate (simul_rb_root *T, simul_rb_node *node);
uint32_t simul_rb_transplant (simul_rb_root *T, simul_rb_node *pre_node, simul_rb_node *chg_node);
simul_rb_node *simul_rb_minimum (simul_rb_node *node);

uint32_t simul_rb_insert (simul_rb_root *T, uint64_t inkey);
void simul_rb_insert_fixup (simul_rb_root *T, simul_rb_node *alt_node);
uint32_t simul_rb_delete (simul_rb_root *T, uint64_t delkey);
void simul_rb_delete_fixup (simul_rb_root *T, simul_rb_node *chg_node);
simul_rb_node *simul_rb_search (simul_rb_root *T, uint64_t find_key);

#endif
#endif
