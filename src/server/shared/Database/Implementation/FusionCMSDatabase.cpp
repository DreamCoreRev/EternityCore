/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "FusionCMSDatabase.h"

void FusionCMSDatabaseConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_FUSIONCMSDATABASE_STATEMENTS);
    
    // BattlePay
	PrepareStatement(FUSION_SEL_BATTLEPAY_COINS, "SELECT dp FROM users WHERE id = ?", CONNECTION_SYNCH);
	PrepareStatement(FUSION_UPD_BATTLEPAY_INCREMENT_COINS, "UPDATE users SET dp = dp + ? WHERE id = ?", CONNECTION_SYNCH);
	PrepareStatement(FUSION_UPD_BATTLEPAY_DECREMENT_COINS, "UPDATE users SET dp = dp - ? WHERE id = ?;", CONNECTION_SYNCH);

    // Custom Reward
    PrepareStatement(FUSION_UPD_BATTLEPAY_VP_COINS, "UPDATE users SET vp = vp + ? WHERE id = ?;", CONNECTION_SYNCH);
}