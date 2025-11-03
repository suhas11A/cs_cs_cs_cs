CC := gcc
CXX := g++
CFLAGS := -Wall -O3 -g -std=gnu99
CXXFLAGS := -Wall -O3 -g -std=c++17
CPPFLAGS :=  -Iinc -MMD -MP
LDFLAGS := -static -Wl,-rpath=/usr/lib/x86_64-linux-gnu/libstdc++.so.6
LDLIBS := -L/usr/lib/x86_64-linux-gnu/libstdc++.so.6 -lstdc++

.phony: all clean

all: bin/nira

clean: 
	$(RM) inc/champsim_constants.h
	$(RM) src/core_inst.cc
	$(RM) inc/cache_modules.inc
	$(RM) inc/ooo_cpu_modules.inc
	 find . -name \*.o -delete
	 find . -name \*.d -delete
	 $(RM) -r obj

	 find replacement/rrip -name \*.o -delete
	 find replacement/rrip -name \*.d -delete
	 find prefetcher/no -name \*.o -delete
	 find prefetcher/no -name \*.d -delete
	 find replacement/nru -name \*.o -delete
	 find replacement/nru -name \*.d -delete
	 find prefetcher/no_instr -name \*.o -delete
	 find prefetcher/no_instr -name \*.d -delete
	 find replacement/plru -name \*.o -delete
	 find replacement/plru -name \*.d -delete
	 find replacement/pc-based -name \*.o -delete
	 find replacement/pc-based -name \*.d -delete
	 find replacement/lru -name \*.o -delete
	 find replacement/lru -name \*.d -delete
	 find branch/bimodal -name \*.o -delete
	 find branch/bimodal -name \*.d -delete
	 find btb/basic_btb -name \*.o -delete
	 find btb/basic_btb -name \*.d -delete

bin/nira: $(patsubst %.cc,%.o,$(wildcard src/*.cc)) obj/repl_rreplacementDrrip.a obj/pref_pprefetcherDno.a obj/repl_rreplacementDnru.a obj/pref_pprefetcherDno_instr.a obj/repl_rreplacementDplru.a obj/repl_rreplacementDpcHbased.a obj/repl_rreplacementDlru.a obj/bpred_bbranchDbimodal.a obj/btb_bbtbDbasic_btb.a
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

replacement/rrip/%.o: CFLAGS += -Ireplacement/rrip
replacement/rrip/%.o: CXXFLAGS += -Ireplacement/rrip
replacement/rrip/%.o: CXXFLAGS +=  -Dinitialize_replacement=repl_rreplacementDrrip_initialize -Dfind_victim=repl_rreplacementDrrip_victim -Dupdate_replacement_state=repl_rreplacementDrrip_update -Dreplacement_final_stats=repl_rreplacementDrrip_final_stats
obj/repl_rreplacementDrrip.a: $(patsubst %.cc,%.o,$(wildcard replacement/rrip/*.cc)) $(patsubst %.c,%.o,$(wildcard replacement/rrip/*.c))
	@mkdir -p $(dir $@)
	ar -rcs $@ $^

prefetcher/no/%.o: CFLAGS += -Iprefetcher/no
prefetcher/no/%.o: CXXFLAGS += -Iprefetcher/no
prefetcher/no/%.o: CXXFLAGS +=  -Dprefetcher_initialize=pref_pprefetcherDno_initialize -Dprefetcher_cache_operate=pref_pprefetcherDno_cache_operate -Dprefetcher_cache_fill=pref_pprefetcherDno_cache_fill -Dprefetcher_cycle_operate=pref_pprefetcherDno_cycle_operate -Dprefetcher_final_stats=pref_pprefetcherDno_final_stats -Dl1d_prefetcher_initialize=pref_pprefetcherDno_initialize -Dl2c_prefetcher_initialize=pref_pprefetcherDno_initialize -Dllc_prefetcher_initialize=pref_pprefetcherDno_initialize -Dl1d_prefetcher_operate=pref_pprefetcherDno_cache_operate -Dl2c_prefetcher_operate=pref_pprefetcherDno_cache_operate -Dllc_prefetcher_operate=pref_pprefetcherDno_cache_operate -Dl1d_prefetcher_cache_fill=pref_pprefetcherDno_cache_fill -Dl2c_prefetcher_cache_fill=pref_pprefetcherDno_cache_fill -Dllc_prefetcher_cache_fill=pref_pprefetcherDno_cache_fill -Dl1d_prefetcher_final_stats=pref_pprefetcherDno_final_stats -Dl2c_prefetcher_final_stats=pref_pprefetcherDno_final_stats -Dllc_prefetcher_final_stats=pref_pprefetcherDno_final_stats
obj/pref_pprefetcherDno.a: $(patsubst %.cc,%.o,$(wildcard prefetcher/no/*.cc)) $(patsubst %.c,%.o,$(wildcard prefetcher/no/*.c))
	@mkdir -p $(dir $@)
	ar -rcs $@ $^

replacement/nru/%.o: CFLAGS += -Ireplacement/nru
replacement/nru/%.o: CXXFLAGS += -Ireplacement/nru
replacement/nru/%.o: CXXFLAGS +=  -Dinitialize_replacement=repl_rreplacementDnru_initialize -Dfind_victim=repl_rreplacementDnru_victim -Dupdate_replacement_state=repl_rreplacementDnru_update -Dreplacement_final_stats=repl_rreplacementDnru_final_stats
obj/repl_rreplacementDnru.a: $(patsubst %.cc,%.o,$(wildcard replacement/nru/*.cc)) $(patsubst %.c,%.o,$(wildcard replacement/nru/*.c))
	@mkdir -p $(dir $@)
	ar -rcs $@ $^

prefetcher/no_instr/%.o: CFLAGS += -Iprefetcher/no_instr
prefetcher/no_instr/%.o: CXXFLAGS += -Iprefetcher/no_instr
prefetcher/no_instr/%.o: CXXFLAGS +=  -Dprefetcher_initialize=pref_pprefetcherDno_instr_initialize -Dprefetcher_branch_operate=pref_pprefetcherDno_instr_branch_operate -Dprefetcher_cache_operate=pref_pprefetcherDno_instr_cache_operate -Dprefetcher_cycle_operate=pref_pprefetcherDno_instr_cycle_operate -Dprefetcher_cache_fill=pref_pprefetcherDno_instr_cache_fill -Dprefetcher_final_stats=pref_pprefetcherDno_instr_final_stats -Dl1i_prefetcher_initialize=pref_pprefetcherDno_instr_initialize -Dl1i_prefetcher_branch_operate=pref_pprefetcherDno_instr_branch_operate -Dl1i_prefetcher_cache_operate=pref_pprefetcherDno_instr_cache_operate -Dl1i_prefetcher_cycle_operate=pref_pprefetcherDno_instr_cycle_operate -Dl1i_prefetcher_cache_fill=pref_pprefetcherDno_instr_cache_fill -Dl1i_prefetcher_final_stats=pref_pprefetcherDno_instr_final_stats
obj/pref_pprefetcherDno_instr.a: $(patsubst %.cc,%.o,$(wildcard prefetcher/no_instr/*.cc)) $(patsubst %.c,%.o,$(wildcard prefetcher/no_instr/*.c))
	@mkdir -p $(dir $@)
	ar -rcs $@ $^

replacement/plru/%.o: CFLAGS += -Ireplacement/plru
replacement/plru/%.o: CXXFLAGS += -Ireplacement/plru
replacement/plru/%.o: CXXFLAGS +=  -Dinitialize_replacement=repl_rreplacementDplru_initialize -Dfind_victim=repl_rreplacementDplru_victim -Dupdate_replacement_state=repl_rreplacementDplru_update -Dreplacement_final_stats=repl_rreplacementDplru_final_stats
obj/repl_rreplacementDplru.a: $(patsubst %.cc,%.o,$(wildcard replacement/plru/*.cc)) $(patsubst %.c,%.o,$(wildcard replacement/plru/*.c))
	@mkdir -p $(dir $@)
	ar -rcs $@ $^

replacement/pc-based/%.o: CFLAGS += -Ireplacement/pc-based
replacement/pc-based/%.o: CXXFLAGS += -Ireplacement/pc-based
replacement/pc-based/%.o: CXXFLAGS +=  -Dinitialize_replacement=repl_rreplacementDpcHbased_initialize -Dfind_victim=repl_rreplacementDpcHbased_victim -Dupdate_replacement_state=repl_rreplacementDpcHbased_update -Dreplacement_final_stats=repl_rreplacementDpcHbased_final_stats
obj/repl_rreplacementDpcHbased.a: $(patsubst %.cc,%.o,$(wildcard replacement/pc-based/*.cc)) $(patsubst %.c,%.o,$(wildcard replacement/pc-based/*.c))
	@mkdir -p $(dir $@)
	ar -rcs $@ $^

replacement/lru/%.o: CFLAGS += -Ireplacement/lru
replacement/lru/%.o: CXXFLAGS += -Ireplacement/lru
replacement/lru/%.o: CXXFLAGS +=  -Dinitialize_replacement=repl_rreplacementDlru_initialize -Dfind_victim=repl_rreplacementDlru_victim -Dupdate_replacement_state=repl_rreplacementDlru_update -Dreplacement_final_stats=repl_rreplacementDlru_final_stats
obj/repl_rreplacementDlru.a: $(patsubst %.cc,%.o,$(wildcard replacement/lru/*.cc)) $(patsubst %.c,%.o,$(wildcard replacement/lru/*.c))
	@mkdir -p $(dir $@)
	ar -rcs $@ $^

branch/bimodal/%.o: CFLAGS += -Ibranch/bimodal
branch/bimodal/%.o: CXXFLAGS += -Ibranch/bimodal
branch/bimodal/%.o: CXXFLAGS +=  -Dinitialize_branch_predictor=bpred_bbranchDbimodal_initialize -Dlast_branch_result=bpred_bbranchDbimodal_last_result -Dpredict_branch=bpred_bbranchDbimodal_predict
obj/bpred_bbranchDbimodal.a: $(patsubst %.cc,%.o,$(wildcard branch/bimodal/*.cc)) $(patsubst %.c,%.o,$(wildcard branch/bimodal/*.c))
	@mkdir -p $(dir $@)
	ar -rcs $@ $^

btb/basic_btb/%.o: CFLAGS += -Ibtb/basic_btb
btb/basic_btb/%.o: CXXFLAGS += -Ibtb/basic_btb
btb/basic_btb/%.o: CXXFLAGS +=  -Dinitialize_btb=btb_bbtbDbasic_btb_initialize -Dupdate_btb=btb_bbtbDbasic_btb_update -Dbtb_prediction=btb_bbtbDbasic_btb_predict
obj/btb_bbtbDbasic_btb.a: $(patsubst %.cc,%.o,$(wildcard btb/basic_btb/*.cc)) $(patsubst %.c,%.o,$(wildcard btb/basic_btb/*.c))
	@mkdir -p $(dir $@)
	ar -rcs $@ $^

-include $(wildcard src/*.d)
-include $(wildcard replacement/rrip/*.d)
-include $(wildcard prefetcher/no/*.d)
-include $(wildcard replacement/nru/*.d)
-include $(wildcard prefetcher/no_instr/*.d)
-include $(wildcard replacement/plru/*.d)
-include $(wildcard replacement/pc-based/*.d)
-include $(wildcard replacement/lru/*.d)
-include $(wildcard branch/bimodal/*.d)
-include $(wildcard btb/basic_btb/*.d)

