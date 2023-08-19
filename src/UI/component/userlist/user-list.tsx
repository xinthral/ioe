// Import deps
import React from 'react'

// Import components
import { UserListRow } from './user-list-row'

// Import styles
import './user-list.css'

// Create interfaces
interface UserUI {
  id: number;
  username: string;
  nickname: string;
  rating: number;
}

interface UserListUI {
  users: UserUI[];
  loading: boolean;
  handleUserRemove: (id: number, username: string) => void;
}

// Create BookshelfList component
export const BookshelfList = (props: UserListUI) => {
  // Show loading message
  if (props.loading) return <p>Leaderboard table is loading...</p>

  return (
    <table className="table">
        <thead>
          <tr>
            <th className="table-head-item" />

            <th className="table-head-item">Username</th>

            <th className="table-head-item">Nickname</th>

            <th className="table-head-item">Rating</th>

            <th className="table-head-item" />
          </tr>
        </thead>

        <tbody className="table-body">
          {props.users.length > 0 ? (
            props.users.map((user: UserUI, idx) => (
              <UserListRow
                key={user.id}
                user={user}
                position={idx + 1}
                handleUserRemove={props.handleUserRemove}
              />
              )
            )
          ) : (
            <tr className="table-row">
              <td className="table-item" style={{ textAlign: 'center' }} colSpan={6}>There are no users to show!</td>
            </tr>
          )
        }
        </tbody>
    </table>
  )
}