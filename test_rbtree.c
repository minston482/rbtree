#include <linux/module.h>
#include <linux/blkdev.h> /* bio */
#include <linux/kthread.h>
#include <linux/kernel.h>
#include <linux/vmalloc.h>

#define CREATE_TRACE_POINTS
#include "hello-trace.h"
#include "rbtree.c"

static int hello_init(void)
{
	int64_t i = 0;
	uint32_t retval = 0;
	simul_rb_root *root = simul_rb_alloc_root();
	simul_rb_node *node = NULL;

	init_rb_root (root);
	simul_rb_insert (root, 5);
	simul_rb_insert (root, 3);
	simul_rb_insert (root, 2);
	simul_rb_insert (root, 6);
	simul_rb_insert (root, 9);
	simul_rb_insert (root, 8);
	simul_rb_insert (root, 7);
	simul_rb_insert (root, 1);
	printk("insert end\n");
	for( i = 0; i< 10; i++) {
		node = simul_rb_search(root, i);
		if (node == root->nil_node)
			printk("%lld is not in rbtree\n", i);
		else
			printk("%lld is in rbtree\n",i);
	}
	printk("end of search\n");
	printk("pre-order start\n");
	simul_rb_pre_order(root, root->root_node->rb_left);
	printk("pre-order end\n");
	printk("del test\n");
	retval = simul_rb_delete (root, 8);
	if (retval != 0)
		printk("del error\n");

	printk("after del 8 pre-order start\n");
	simul_rb_pre_order(root, root->root_node->rb_left);
	printk("pre-order end\n");
	
	retval = simul_rb_delete (root, 2);
	if (retval != 0)
		printk("del error\n");

	printk("after del 2 pre-order start\n");
	simul_rb_pre_order(root, root->root_node->rb_left);
	printk("pre-order end\n");

	retval = simul_rb_delete (root, 3);
	if (retval != 0)
		printk("del error\n");

	set_current_state(TASK_INTERRUPTIBLE);
	schedule_timeout(HZ);
	trace_me_simul(jiffies, 0);
	printk("after del 3 pre-order start\n");
	simul_rb_pre_order(root, root->root_node->rb_left);
	printk("pre-order end\n");

    return 0;
}

static void hello_exit(void)
{
    printk("Goodby");
}

module_init(hello_init);
module_exit(hello_exit);

//MODULE_AUTHOR("Steven Rostedt");
//MODULE_DESCRIPTION("silly-module");
MODULE_LICENSE("GPL");
