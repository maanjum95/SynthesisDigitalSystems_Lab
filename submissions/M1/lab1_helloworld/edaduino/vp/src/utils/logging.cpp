#include "utils/logging.h"
#include <systemc>

using namespace sc_core;

void etissvp::set_log_level(etiss::Verbosity log_level) {
  switch (log_level) {
    case etiss::SILENT:
      sc_report_handler::set_actions(SC_INFO, SC_DO_NOTHING);
      sc_report_handler::set_actions(SC_WARNING, SC_DO_NOTHING);
      sc_report_handler::set_actions(SC_ERROR, SC_DO_NOTHING);
      sc_report_handler::set_actions(SC_FATAL, SC_ABORT);
      break;

    case etiss::FATALERROR:
      sc_report_handler::set_actions(SC_INFO, SC_DO_NOTHING);
      sc_report_handler::set_actions(SC_WARNING, SC_DO_NOTHING);
      sc_report_handler::set_actions(SC_ERROR, SC_DO_NOTHING);
      sc_report_handler::set_actions(SC_FATAL, SC_LOG | SC_DISPLAY | SC_ABORT);
      break;

    case etiss::ERROR:
      sc_report_handler::set_actions(SC_INFO, SC_DO_NOTHING);
      sc_report_handler::set_actions(SC_WARNING, SC_DO_NOTHING);
      sc_report_handler::set_actions(SC_ERROR, SC_LOG | SC_DISPLAY);
      sc_report_handler::set_actions(SC_FATAL, SC_LOG | SC_DISPLAY | SC_ABORT);
      break;

    case etiss::WARNING:
      sc_report_handler::set_actions(SC_INFO, SC_DO_NOTHING);
      sc_report_handler::set_actions(SC_WARNING, SC_LOG | SC_DISPLAY);
      sc_report_handler::set_actions(SC_ERROR, SC_LOG | SC_DISPLAY);
      sc_report_handler::set_actions(SC_FATAL, SC_LOG | SC_DISPLAY | SC_ABORT);
      break;

    case etiss::INFO:
      sc_report_handler::set_actions(SC_INFO, SC_LOG | SC_DISPLAY);
      sc_report_handler::set_actions(SC_WARNING, SC_LOG | SC_DISPLAY);
      sc_report_handler::set_actions(SC_ERROR, SC_LOG | SC_DISPLAY);
      sc_report_handler::set_actions(SC_FATAL, SC_LOG | SC_DISPLAY | SC_ABORT);
      break;

    case etiss::VERBOSE:
      sc_report_handler::set_actions(SC_INFO, SC_LOG | SC_DISPLAY);
      sc_report_handler::set_actions(SC_WARNING, SC_LOG | SC_DISPLAY);
      sc_report_handler::set_actions(SC_ERROR, SC_LOG | SC_DISPLAY);
      sc_report_handler::set_actions(SC_FATAL, SC_LOG | SC_DISPLAY | SC_ABORT);
      break;
  };
}
