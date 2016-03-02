#pragma once
#include "mgc_vista_schematics.h"
$includes_begin;
#include <systemc.h>
#include "zynq_schematics/Zynq_SoC.h"
#include "../../fpga_hw/schematics/FPGA_fabric.h"
#include "../../fpga_hw/models/axi32_axi128_model.h"
#include "../../fpga_hw/models/axi128_axi32_model.h"
$includes_end;

$module_begin("zynqIP");
SC_MODULE(zynqIP) {
public:
  typedef zynqIP SC_CURRENT_USER_MODULE;
  zynqIP(::sc_core::sc_module_name name):
    ::sc_core::sc_module(name)
    $initialization_begin
$init("Zynq_SoC_inst"),
Zynq_SoC_inst(0)
$end
$init("fpga_inst"),
fpga_inst(0)
$end
$init("c3"),
c3(0)
$end
$init("c4"),
c4(0)
$end
    $initialization_end
{
    $elaboration_begin;
$create_component("Zynq_SoC_inst");
Zynq_SoC_inst = new Zynq_SoC("Zynq_SoC_inst");
$end;
$create_component("fpga_inst");
fpga_inst = new FPGA_fabric("fpga_inst");
$end;
$create_component("c3");
c3 = new axi32_axi128_pvt("c3");
$end;
$create_component("c4");
c4 = new axi128_axi32_pvt("c4");
$end;
$bind("fpga_inst->jpeg_irq","Zynq_SoC_inst->PL1_IRQ");
vista_bind(fpga_inst->jpeg_irq, Zynq_SoC_inst->PL1_IRQ);
$end;
$bind("fpga_inst->ic_irq","Zynq_SoC_inst->PL0_IRQ");
vista_bind(fpga_inst->ic_irq, Zynq_SoC_inst->PL0_IRQ);
$end;
$bind("fpga_inst->ip_irq","Zynq_SoC_inst->PL2_IRQ");
vista_bind(fpga_inst->ip_irq, Zynq_SoC_inst->PL2_IRQ);
$end;
$bind("c3->master","fpga_inst->FPGAslave");
vista_bind(c3->master, fpga_inst->FPGAslave);
$end;
$bind("Zynq_SoC_inst->M_AXI_GP0","c3->slave");
vista_bind(Zynq_SoC_inst->M_AXI_GP0, c3->slave);
$end;
$bind("c4->master","Zynq_SoC_inst->S_AXI_GP0");
vista_bind(c4->master, Zynq_SoC_inst->S_AXI_GP0);
$end;
$bind("fpga_inst->FPGAmaster","c4->slave");
vista_bind(fpga_inst->FPGAmaster, c4->slave);
$end;
    $elaboration_end;
  $vlnv_assign_begin;
m_library = "schematics";
m_vendor = "";
m_version = "";
  $vlnv_assign_end;
  }
  ~zynqIP() {
    $destructor_begin;
$destruct_component("Zynq_SoC_inst");
delete Zynq_SoC_inst; Zynq_SoC_inst = 0;
$end;
$destruct_component("fpga_inst");
delete fpga_inst; fpga_inst = 0;
$end;
$destruct_component("c3");
delete c3; c3 = 0;
$end;
$destruct_component("c4");
delete c4; c4 = 0;
$end;
    $destructor_end;
  }
public:
  $fields_begin;
$component("Zynq_SoC_inst");
Zynq_SoC *Zynq_SoC_inst;
$end;
$component("fpga_inst");
FPGA_fabric *fpga_inst;
$end;
$component("c3");
axi32_axi128_pvt *c3;
$end;
$component("c4");
axi128_axi32_pvt *c4;
$end;
  $fields_end;
  $vlnv_decl_begin;
public:
const char* m_library;
const char* m_vendor;
const char* m_version;
  $vlnv_decl_end;
};
$module_end;